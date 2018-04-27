/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "MainController.h"
#include "../View/AboutView.h"
#include "../View/MainView.h"
#include "../Model/MainModel.h"
#include "../Model/SettingsModel.h"
#include "../View/SettingsView.h"
#include "../Data/FileSyncData.h"
#include "../Data/SyncFoldersData.h"
#include "../../Core/FileManager.h"
#include "../Data/ActionType.h"
#include "../Data/CategoryType.h"

#include <QMessageBox>
#include <QtCore>

using namespace Client::View;
using namespace Client::Model;
using namespace Client::Data;
using namespace Core;

namespace Client { namespace Controller
{
	MainController::MainController(MainModel *model, SettingsModel *settingsModel, const MainView *mainView) : model(model), settingsModel(settingsModel)
	{ 
		QObject::connect(threadManagerCompare.GetThread(), SIGNAL(SendObject(void *)), mainView, SLOT(CompareSendObject(void *)));
		QObject::connect(threadManagerCompare.GetThread(), SIGNAL(Finish()), mainView, SLOT(CompareFinish()));

		QObject::connect(threadManagerSync.GetThread(), SIGNAL(Finish()), mainView, SLOT(SyncFinish()));
		QObject::connect(threadManagerSync.GetThread(), SIGNAL(ProgressPercent(int)), mainView, SLOT(SyncPercent(int)));
		QObject::connect(threadManagerSync.GetThread(), SIGNAL(IndexApply(int)), mainView, SLOT(SyncIndexApply(int)));
	}

	MainController::~MainController()
	{
		if (settingsView != nullptr)
			delete settingsView;

		if (aboutView != nullptr)
			delete aboutView;
	}

	QString MainController::GetFileSizeStat(qint64 fileSize, bool isFolder) const
	{
		if (isFolder)
			return "";

		if (fileSize == 0)
			return "0 byte";

		const int quantity = 1024;
		const int quantityDimension = static_cast<float>(log(fileSize)) / static_cast<float>(log(quantity));
		QString result = QString::number(roundf(fileSize / pow(quantity, quantityDimension) * 10) / 10);

		switch (quantityDimension)
		{
		case 0: result += " bytes"; break;
		case 1: result += " Kb"; break;
		case 2: result += " Mb"; break;
		case 3: result += " Gb"; break;
		case 4: result += " Tb"; break;

		default:;
		}

		return result;
	}

	void MainController::SetSyncFileList(const QList<SyncFoldersData> &folderList)
	{
		threadManagerCompare.SetRunMethod([this, folderList]()
		{
			static QMap<QString, FileSyncData> tempSyncFileList;
			tempSyncFileList.clear();

			const auto dirAttribs = QDir::AllDirs | QDir::Files | QDir::Hidden | QDir::NoDotAndDotDot;
			for (auto foldersItem : folderList)
			{
				QDirIterator leftIterator(foldersItem.folderLeft, dirAttribs, QDirIterator::Subdirectories);
				while (threadManagerCompare.GetIsCanRun() && leftIterator.hasNext())
				{
					leftIterator.next();

					const QFileInfo &info = leftIterator.fileInfo();

					if (info.fileName().length() == 0)
					{
						leftIterator.next();
						continue;
					}

					QString relativeFolder(info.absoluteFilePath().remove(0, foldersItem.folderLeft.length()));

					FileSyncData data;
					data.folderLeft = foldersItem.folderLeft;
					data.folderRight = foldersItem.folderRight;

					data.leftFile.relativeFolderAndName = relativeFolder;
					data.leftFile.name = "/" + info.fileName();

					if (relativeFolder == data.leftFile.name)
						data.leftFile.relativeFolder = "";
					else
						data.leftFile.relativeFolder = relativeFolder.size() == 0 ? "" : relativeFolder.remove(relativeFolder.count() - data.leftFile.name.count(), data.leftFile.name.count());
					
					data.leftFile.modifiedTime = info.lastModified();
					data.leftFile.fileSize = info.size();
					data.leftFile.fileSizeStat = GetFileSizeStat(info.size(), info.isDir() && !info.isSymLink());
					data.leftFile.isFolder = info.isDir() && !info.isSymLink();
					data.leftFile.isSymlink = info.isSymLink();
					data.leftFile.isHidden = info.isHidden();

					SetCategoryAndActionType(&data);

					tempSyncFileList.insert(data.leftFile.relativeFolderAndName, data);
				}

				QDirIterator rightIterator(foldersItem.folderRight, dirAttribs, QDirIterator::Subdirectories);
				while (threadManagerCompare.GetIsCanRun() && rightIterator.hasNext())
				{
					rightIterator.next();

					const QFileInfo &info = rightIterator.fileInfo();

					if (info.fileName().length() == 0)
					{
						rightIterator.next();
						continue;
					}

					QString relativeFolder(info.absoluteFilePath().remove(0, foldersItem.folderRight.length()));

					FileData rightFileData;
					rightFileData.relativeFolderAndName = relativeFolder;
					rightFileData.name = "/" + info.fileName();

					if (relativeFolder == rightFileData.name)
						rightFileData.relativeFolder = "";
					else
						rightFileData.relativeFolder = relativeFolder.size() == 0 ? "" : relativeFolder.remove(relativeFolder.count() - rightFileData.name.count(), rightFileData.name.count());

					rightFileData.modifiedTime = info.lastModified();
					rightFileData.fileSize = info.size();
					rightFileData.fileSizeStat = GetFileSizeStat(info.size(), info.isDir() && !info.isSymLink());
					rightFileData.isFolder = info.isDir() && !info.isSymLink();
					rightFileData.isSymlink = info.isSymLink();
					rightFileData.isHidden = info.isHidden();

					if (tempSyncFileList.contains(rightFileData.relativeFolderAndName))
					{
						FileSyncData *fileSyncData = &(tempSyncFileList[rightFileData.relativeFolderAndName]); //warning! QMap operator [] insert new pair if the key doesn't exist!
						if (fileSyncData->leftFile == rightFileData)
							tempSyncFileList.remove(rightFileData.relativeFolderAndName);
						else
						{
							fileSyncData->rightFile = rightFileData;
							SetCategoryAndActionType(fileSyncData);
						}
					}
					else
					{
						FileSyncData data;
						data.folderLeft = foldersItem.folderLeft;
						data.folderRight = foldersItem.folderRight;

						data.rightFile = rightFileData;
					
						SetCategoryAndActionType(&data);

						tempSyncFileList.insert(rightFileData.relativeFolderAndName, data);
					}
				}
			}
	
			threadManagerCompare.SetSendObject(threadManagerCompare.GetIsCanRun() ? &tempSyncFileList : nullptr);
		});

		threadManagerCompare.Start();
	}

	void MainController::SetCategoryAndActionType(FileSyncData *fileSyncDataOut) const
	{
		if (fileSyncDataOut->leftFile.relativeFolderAndName.count() > 0)
		{
			if (fileSyncDataOut->rightFile.relativeFolderAndName.count() > 0) //left and right
			{
				if (fileSyncDataOut->leftFile.modifiedTime > fileSyncDataOut->rightFile.modifiedTime)
				{
					fileSyncDataOut->action = static_cast<ActionType>(settingsModel->GetLeftNew());
					fileSyncDataOut->category = CategoryType::LeftNew;
				}
				else
				{
					fileSyncDataOut->action = static_cast<ActionType>(settingsModel->GetRightNew());
					fileSyncDataOut->category = CategoryType::RightNew;
				}
			}
			else //left
			{
				fileSyncDataOut->action = static_cast<ActionType>(settingsModel->GetLeftOnly());
				fileSyncDataOut->category = CategoryType::LeftOnly;
			}
		}
		else //right
		{
			fileSyncDataOut->action = static_cast<ActionType>(settingsModel->GetRightOnly());
			fileSyncDataOut->category = CategoryType::RightOnly;
		}
	}

	bool MainController::CompareFiles()
	{
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Critical);
		const QString message("This folder does not exist: ");
		auto folderList = model->GetFolderItemList();

		for (const auto folderItem : folderList)
		{
			if (!QDir(folderItem.folderLeft).exists())
			{
				msgBox.setText(message + folderItem.folderLeft);
				msgBox.exec();

				return false;
			}

			if (!QDir(folderItem.folderRight).exists())
			{
				msgBox.setText(message + folderItem.folderRight);
				msgBox.exec();

				return false;
			}

			if (folderItem.folderLeft == folderItem.folderRight)
			{
				QMessageBox msgBox2;
				msgBox2.setIcon(QMessageBox::Warning);
				msgBox2.setText("Any folder pair is equal!");
				msgBox2.exec();
				
				return false;
			}
		}

		SetSyncFileList(folderList);

		return true;
	}

	void MainController::SyncFiles(const QMap<QString, FileSyncData> *syncFileList)
	{
		threadManagerSync.SetRunMethod([this, syncFileList]()
		{
			const float percentUnit = 100 / static_cast<float>(syncFileList->count());
			float percent = 0;
		
			for (int index = 0; threadManagerSync.GetIsCanRun() && index < syncFileList->count(); index++)
			{
				auto data = syncFileList->values()[index];

				switch (data.action)
				{
					/*
						| <-X|
						|X<-X|
					*/
					case ActionType::CopyRight:
					case ActionType::OverrideLeft:
						FileManager::Copy(data.folderRight + data.rightFile.relativeFolder, data.folderLeft + data.rightFile.relativeFolder, data.rightFile.name, data.rightFile.isFolder, data.rightFile.isHidden);
						break;

					/*
						|X-> |
						|X->X|
					*/
					case ActionType::CopyLeft:
					case ActionType::OverrideRight:
						FileManager::Copy(data.folderLeft + data.leftFile.relativeFolder, data.folderRight + data.leftFile.relativeFolder, data.leftFile.name, data.leftFile.isFolder, data.leftFile.isHidden);
						break;

					/*
						|X |
					*/
					case ActionType::DeleteLeft:
						FileManager::Delete(data.folderLeft + data.leftFile.relativeFolderAndName, data.leftFile.isFolder);
						break;

					/*
						| X|
					*/
					case ActionType::DeleteRight:
						FileManager::Delete(data.folderRight + data.rightFile.relativeFolderAndName, data.rightFile.isFolder);
						break;

					default:
						;
				}

				percent += percentUnit;
				threadManagerSync.SetProgressPercent(percent);

				threadManagerSync.SetIndexApply(index);
			}

			if (threadManagerSync.GetIsCanRun() && percent < 100)
				threadManagerSync.SetProgressPercent(100);
		});

		threadManagerSync.Start();
	}

	void MainController::Stop()
	{
		threadManagerCompare.Stop();
		threadManagerSync.Stop();
	}

	void MainController::Save() const
	{
		model->Save();

		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setText("Workflow has been saved.");
		msgBox.exec();
	}

	void MainController::Settings()
	{
		if (settingsView == nullptr)
			settingsView = new SettingsView(nullptr, settingsModel);

		settingsView->Init();
		settingsView->show();
	}

	void MainController::About()
	{
		if (aboutView == nullptr)
			aboutView = new AboutView;

		aboutView->show();
	}

	void MainController::WorkflowItemChanged(int index) const
	{
		model->SetWorkflowItemIndex(index);
	}
}}
