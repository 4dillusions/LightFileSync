/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "MainView.h"
#include "../Data/FileSyncData.h"
#include "../Data/ActionType.h"
#include "../Data/CategoryType.h"
#include "../Model/MainModel.h"
#include "../Model/SettingsModel.h"
#include "../Model/ModelFactory.h"
#include "../Controller/MainController.h"
#include "../../Core/Tuple.h"
#include "../../Core/Thread.h"
#include "ResourceFactory.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QLabel>

using namespace Client::Model;
using namespace Client::Controller;
using namespace Client::Data;
using namespace Core;

namespace Client { namespace View
{
	MainView::MainView(QWidget *parent)
		: QMainWindow(parent)
	{
		ui = new Ui::MainViewClass;
		ui->setupUi(this);

		connect(ui->WorkflowText, SIGNAL(textEdited(QString)), this, SLOT(WorkflowTextEdited(QString)));

		model = ModelFactory::CreateMainModel();
		settingsModel = ModelFactory::CreateSettingsModel();

		controller = new MainController(model, settingsModel, this);
	
		actionIconList = ResourceFactory::CreateActionIconList();
		categoryIconList = ResourceFactory::CreateCategoryIconList();

		Init();
	}

	MainView::~MainView()
	{
		if (GetTittleIsModified() && QMessageBox::question(this, ("Save Workflow"), ("Do yout want to save workflow?"), QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton) == QMessageBox::Yes)
			controller->Save();

		delete model;
		delete settingsModel;
		delete controller;
		delete ui;
	}

	bool MainView::GetTittleIsModified() const
	{
		return windowTitle().contains('*');
	}

	void MainView::SetIsModified(bool isModified)
	{
		if (isModified)
		{
			if (!GetTittleIsModified())
				setWindowTitle(windowTitle() + "*");
		}
		else
		{
			if (GetTittleIsModified())
				setWindowTitle(windowTitle().remove(windowTitle().length() - 1, 1));
		}

		ui->actionSave->setEnabled(isModified);
	}

	void MainView::SetIsSync(bool isSync) const
	{
		ui->actionSync->setEnabled(!isSync);
		ui->actionStop->setEnabled(isSync);
		ui->actionSave->setEnabled(GetTittleIsModified() && !isSync);
		ui->actionSettings->setEnabled(!isSync);
		ui->actionInfo->setEnabled(!isSync);

		ui->AddWorkflowButton->setEnabled(!isSync);
		ui->DeleteWorkflowButton->setEnabled(!isSync);
		ui->WorkflowText->setEnabled(!isSync);
		ui->WorkflowItemList->setEnabled(!isSync);

		ui->FoldersTable->setEnabled(!isSync);
		ui->AddSyncFoldersButton->setEnabled(!isSync);
		ui->DeleteSyncFoldersButton->setEnabled(!isSync);
		ui->LeftFolderText->setEnabled(!isSync);
		ui->RightFolderText->setEnabled(!isSync);
		ui->BrowseFolderLeftButton->setEnabled(!isSync);
		ui->BrowseFolderRightButton->setEnabled(!isSync);
	}

	void MainView::SetIsProgressLoop(bool isMarquee) const
	{
		ui->Progress->setMaximum(isMarquee ? 0 : 100);
	}

	int MainView::GetFoldersTableSelectedIndex() const
	{
		auto indexes = ui->FoldersTable->selectionModel()->selectedIndexes();
		if (indexes.count() > 0)
			return indexes.first().row();

		return -1;
	}

	void MainView::SetCurrentFolderTexts(QLineEdit *text, bool isLeft)
	{
		if (!text->text().isEmpty())
		{
			QFileDialog dialog;
			dialog.setOptions(QFileDialog::ShowDirsOnly);
			dialog.setFileMode(QFileDialog::Directory);

			if (dialog.exec())
			{
				const auto path = dialog.directory().absolutePath();

				text->setText(path);

				const int row = GetFoldersTableSelectedIndex();
				if (row >= 0)
				{
					if (isLeft)
					{
						model->SetFolderItemTexts(row, Tuple2<QString, QString>(path, ""));
						ui->FoldersTable->item(row, 0)->setText(path);
					}
					else
					{
						model->SetFolderItemTexts(row, Tuple2<QString, QString>("", path));
						ui->FoldersTable->item(row, 1)->setText(path);
					}
				}
			
				SetIsModified(true);
			}
		}
	}

	QLabel *MainView::CreatePixmapLabel(const QPixmap &pixmap)
	{
		auto result = new QLabel;
		
		result->setPixmap(pixmap);
		result->setAlignment(Qt::AlignCenter);

		return result;
	}

	void MainView::Init() const
	{
		auto workflowList = model->GetWorkflowItemList();
		if (!workflowList.isEmpty())
		{
			for (int row = 0; row < workflowList.length(); row++)
				ui->WorkflowItemList->insertItem(row, workflowList[row]);

			ui->WorkflowItemList->setCurrentRow(0);
		}

		ui->FoldersTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	
		ui->SyncTable->horizontalHeader()->setSectionResizeMode(static_cast<int>(SyncTableColumns::Leftfile), QHeaderView::Stretch);
		ui->SyncTable->setColumnWidth(static_cast<int>(SyncTableColumns::LeftSize), 70);
		ui->SyncTable->setColumnWidth(static_cast<int>(SyncTableColumns::Category), 48);
		ui->SyncTable->setColumnWidth(static_cast<int>(SyncTableColumns::Action), 48);
		ui->SyncTable->horizontalHeader()->setSectionResizeMode(static_cast<int>(SyncTableColumns::RightFile), QHeaderView::Stretch);
		ui->SyncTable->setColumnWidth(static_cast<int>(SyncTableColumns::RightSize), 70);
		ui->SyncTable->setColumnWidth(static_cast<int>(SyncTableColumns::Completed), 24);
		
		ui->SyncTable->setIconSize(QSize(48, 48));
	}

	void MainView::InitFoldersTable() const
	{
		CleanTable(ui->FoldersTable);

		auto foldersList = model->GetFolderItemList();
		if (!foldersList.isEmpty())
		{
			for (int row = 0; row < foldersList.length(); row++)
			{
				ui->FoldersTable->insertRow(row);
				ui->FoldersTable->setItem(row, 0, new QTableWidgetItem(foldersList[row].folderLeft));
				ui->FoldersTable->setItem(row, 1, new QTableWidgetItem(foldersList[row].folderRight));
			}
		}
	}

	void MainView::CleanTable(QTableWidget *table) const
	{
		SetIsProgressLoop(true);
		table->setVisible(false);
		while (table->rowCount() > 0)
		{
			/*for (int i = 0; i < table->columnCount(); i++)
				delete table->item(0, i);*/
		
			table->removeRow(0);
		}
		table->setVisible(true);
		SetIsProgressLoop(false);
	}

	void MainView::Sync() const
	{
		CleanTable(ui->SyncTable);
		ui->Progress->setValue(0);
		SetIsSync(true);

		SetIsProgressLoop(true);
		if (!controller->CompareFiles())
		{
			controller->Stop();

			SetIsSync(false);
			SetIsProgressLoop(false);
		}
	}

	void MainView::Stop() const
	{
		controller->Stop();

		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.setText("Sync aborted!");
		msgBox.exec();
	}

	void MainView::Save()
	{
		controller->Save();
		static_cast<MainView *>(this)->SetIsModified(false);
	}

	void MainView::Settings() const
	{
		controller->Settings();
	}

	void MainView::About() const
	{
		controller->About();
	}

	void MainView::ToolBarTriggered(QAction *action)
	{
		if (action->objectName() == ui->actionSync->objectName())
			Sync();

		if (action->objectName() == ui->actionStop->objectName())
			Stop();

		if (action->objectName() == ui->actionSave->objectName())
			Save();

		if (action->objectName() == ui->actionSettings->objectName())
			Settings();

		if (action->objectName() == ui->actionInfo->objectName())
			About();
	}

	void MainView::WorkflowListChanged(int index) const
	{
		controller->WorkflowItemChanged(index);
		InitFoldersTable();
	}

	void MainView::WorkflowTextEdited(const QString &text) const
	{
		if (text.length() > 0)
		{
			ui->WorkflowItemList->selectedItems().first()->setText(text);
			model->SetWorkflowItemText(text);

			const_cast<MainView *>(this)->SetIsModified(true);
		}
	}

	void MainView::WorkflowListAddClick() const
	{
		const int row = ui->WorkflowItemList->count();
		const auto itemName = model->AddNewWorkflowItem(row);
		ui->WorkflowItemList->insertItem(row, itemName);

		const_cast<MainView *>(this)->SetIsModified(true);
	}

	void MainView::WorkflowListDeleteClick() const
	{
		if (ui->WorkflowItemList->count() > 1)
		{
			model->DeleteCurrentWorkflowItem();
			delete ui->WorkflowItemList->item(ui->WorkflowItemList->currentIndex().row());
			ui->WorkflowItemList->setItemSelected(ui->WorkflowItemList->item(0), true);

			const_cast<MainView *>(this)->SetIsModified(true);
		}
	}

	void MainView::FoldersTableItemSelectionChanged() const
	{
		ui->LeftFolderText->setText("");
		ui->RightFolderText->setText("");

		if (ui->FoldersTable->selectedItems().size() > 0)
		{
			const int row = GetFoldersTableSelectedIndex();
			if (row >= 0)
			{
				auto foldersList = model->GetFolderItemList();
				if (!foldersList.isEmpty() && foldersList.count() - 1 >= row)
				{
					ui->LeftFolderText->setText(foldersList[row].folderLeft);
					ui->RightFolderText->setText(foldersList[row].folderRight);
				}
			}
		}
	}

	void MainView::FoldersTableAddClick() const
	{
		const auto folders = model->NewFolderPair();

		const int row = ui->FoldersTable->rowCount();
		ui->FoldersTable->insertRow(row);
		ui->FoldersTable->setItem(row, 0, new QTableWidgetItem(folders.folderLeft));
		ui->FoldersTable->setItem(row, 1, new QTableWidgetItem(folders.folderRight));

		const_cast<MainView *>(this)->SetIsModified(true);
	}

	void MainView::FoldersTableDeleteClick() const
	{
		if (ui->FoldersTable->rowCount() > 1 && GetFoldersTableSelectedIndex() >= 0)
		{
			const int row = GetFoldersTableSelectedIndex();
			if (row >= 0)
			{
				delete ui->FoldersTable->item(row, 0);
				delete ui->FoldersTable->item(row, 1);
				ui->FoldersTable->removeRow(row);

				model->DeleteFolderPair(row);

				const_cast<MainView *>(this)->SetIsModified(true);
			}
		}
	}

	void MainView::FoldersTableLeftBrowseClick() const
	{
		const_cast<MainView *>(this)->SetCurrentFolderTexts(ui->LeftFolderText, true);
	}

	void MainView::FoldersTableRightBrowseClick() const
	{
		const_cast<MainView *>(this)->SetCurrentFolderTexts(ui->RightFolderText, false);
	}

	void MainView::CompareSendObject(void *objOut)
	{
		fileSyncList = static_cast<QMap<QString, FileSyncData> *>(objOut);
	}

	void MainView::CompareFinish() const
	{
		int row = 0;
		qint64 allFileSize = 0;
		SetIsProgressLoop(false);
		ui->actionStop->setEnabled(false);

		if (fileSyncList != nullptr)
		{
			ui->SyncTable->setVisible(false);
			for (auto file : fileSyncList->values())
			{
				ui->SyncTable->insertRow(row);

				ui->SyncTable->setItem(row, static_cast<int>(SyncTableColumns::Leftfile), new QTableWidgetItem(file.leftFile.relativeFolderAndName));
				ui->SyncTable->setItem(row, static_cast<int>(SyncTableColumns::LeftSize), new QTableWidgetItem(file.leftFile.fileSizeStat));
				
				auto tableWidgetCategory = new QTableWidgetItem;
				tableWidgetCategory->setIcon((*categoryIconList)[file.category]);
				ui->SyncTable->setItem(row, static_cast<int>(SyncTableColumns::Category), tableWidgetCategory);

				auto tableWidgetAction = new QTableWidgetItem;
				tableWidgetAction->setIcon((*actionIconList)[file.action]);
				ui->SyncTable->setItem(row, static_cast<int>(SyncTableColumns::Action), tableWidgetAction);

				ui->SyncTable->setItem(row, static_cast<int>(SyncTableColumns::RightFile), new QTableWidgetItem(file.rightFile.relativeFolderAndName));
				ui->SyncTable->setItem(row, static_cast<int>(SyncTableColumns::RightSize), new QTableWidgetItem(file.rightFile.fileSizeStat));

				row++;

				if (file.leftFile.fileSize == 0 || file.rightFile.fileSize == 0)
				{
					allFileSize += file.leftFile.fileSize;
					allFileSize += file.rightFile.fileSize;
				}
				else
					allFileSize += std::max(file.leftFile.fileSize, file.rightFile.fileSize);
			}
			ui->SyncTable->setVisible(true);

			if (fileSyncList->count() > 0)
			{
				QMessageBox msgBox;
				msgBox.setStandardButtons(QMessageBox::Yes);
				msgBox.addButton(QMessageBox::No);
				msgBox.setDefaultButton(QMessageBox::No);
				msgBox.setWindowModality(Qt::NonModal);
				msgBox.setIcon(QMessageBox::Question);
				msgBox.setWindowFlags(msgBox.windowFlags() & ~Qt::WindowContextHelpButtonHint);
				msgBox.setText(QString("Would you like to sync these files?\n\nAll files: ") + QString::number(fileSyncList->count()) + "\nAll size: " + controller->GetFileSizeStat(allFileSize, false));
				msgBox.show();

				if (msgBox.exec() == QMessageBox::Yes)
				{
					SetIsSync(true);
					controller->SyncFiles(fileSyncList);

					return;
				}
			}
			else
			{
				QMessageBox msgBox;
				msgBox.setIcon(QMessageBox::Information);
				msgBox.setText("There isn't any file for sync!");
				msgBox.exec();
			}
		}

		SetIsSync(false);
		CleanTable(ui->SyncTable);
	}

	void MainView::SyncPercent(int percent) const
	{
		ui->Progress->setValue(percent);
	}

	void MainView::SyncIndexApply(int index) const
	{
		auto tableWidget = new QTableWidgetItem;
		tableWidget->setIcon((*actionIconList)[ActionType::Apply]);
		ui->SyncTable->setItem(index, static_cast<int>(SyncTableColumns::Completed), tableWidget);
	}

	void MainView::SyncFinish() const
	{
		if (ui->Progress->value() == 100)
		{
			QMessageBox msgBox;
			msgBox.setIcon(QMessageBox::Information);
			msgBox.setText("File sync succesful!");
			msgBox.exec();
		}

		SetIsSync(false);
	}
}}
