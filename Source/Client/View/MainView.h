/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "ui_MainView.h"

namespace Client { namespace Controller
{
	class MainController;
}}

namespace Client { namespace Model
{
	class MainModel;
	class SettingsModel;
}}

namespace Client { namespace Data
{
	struct FileSyncData;
	enum class ActionType;
	enum class CategoryType;
}}

class QTableWidget;
class QLabel;
class QString;
class QPixmap;
template <typename T1, typename T2> class QMap;

namespace Client { namespace View
{
	class MainView  final : public QMainWindow
	{
		Q_OBJECT

	public:
		MainView(QWidget *parent = Q_NULLPTR);
		~MainView();

	private:
		Ui::MainViewClass *ui;
		Controller::MainController *controller;
		Model::MainModel *model;
		Model::SettingsModel *settingsModel;

		enum class SyncTableColumns
		{
			Leftfile = 0,
			LeftSize = 1,
			Category = 2,
			Action = 3,
			RightFile = 4,
			RightSize = 5,
			Completed = 6
		};

		QMap<Data::ActionType, QIcon> *actionIconList;
		QMap<Data::CategoryType, QIcon> *categoryIconList;
		QMap<QString, Data::FileSyncData> *fileSyncList = nullptr;

		bool GetTittleIsModified() const;
		void SetIsModified(bool isModified);
		void SetIsSync(bool isSync) const;
		void SetIsProgressLoop(bool isProgressLoop) const;

		int GetFoldersTableSelectedIndex() const;
		void SetCurrentFolderTexts(QLineEdit *text, bool isLeft);
		static QLabel *CreatePixmapLabel(const QPixmap &pixmap);

		void Init() const;
		void InitFoldersTable() const;
		void CleanTable(QTableWidget *table) const;

		void Sync() const;
		void Stop() const;
		void Save();
		void Settings() const;
		void About() const;

	public slots:
		void ToolBarTriggered(QAction *action);
	
		void WorkflowTextEdited(const QString &text) const;

		void WorkflowListChanged(int index) const;
		void WorkflowListAddClick() const;
		void WorkflowListDeleteClick() const;

		void FoldersTableItemSelectionChanged() const;
		void FoldersTableAddClick() const;
		void FoldersTableDeleteClick() const;
		void FoldersTableLeftBrowseClick() const;
		void FoldersTableRightBrowseClick() const;

		void CompareSendObject(void *objOut);
		void CompareFinish() const;
		void SyncPercent(int percent) const;
		void SyncIndexApply(int index) const;
		void SyncFinish() const;
	};
}}
