/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "../../Core/ThreadManager.h"

namespace Client { namespace Data
{
	struct FileSyncData;
	struct SyncFoldersData;
}}

namespace Client { namespace Model
{
	class MainModel;
	class SettingsModel;
}}

namespace Client { namespace View
{
	class SettingsView;
	class AboutView;
	class MainView;
}}

class QString;
template <typename T1, typename T2> class QMap;

namespace Client { namespace Controller
{
	class MainController final
	{
		MainController(const MainController &) = delete;
		MainController(MainController &&) = delete;
		MainController &operator=(const MainController &) = delete;
		MainController &operator=(MainController &&) = delete;

		Model::MainModel *model;
		Model::SettingsModel *settingsModel;
		View::SettingsView *settingsView = nullptr;
		View::AboutView *aboutView = nullptr;

		Core::ThreadManager threadManagerCompare;
		Core::ThreadManager threadManagerSync;

		void SetSyncFileList(const QList<Data::SyncFoldersData> &folderList);
		void SetCategoryAndActionType(Data::FileSyncData *fileSyncDataOut) const;

	public:
		explicit MainController(Model::MainModel *model, Model::SettingsModel *settingsModel, const View::MainView *mainView);
		~MainController();

		QString GetFileSizeStat(qint64 fileSize, bool isFolder) const;

		bool CompareFiles();
		void SyncFiles(const QMap<QString, Data::FileSyncData> *syncFileList);
		void Stop();
		void Save() const;
		void Settings();
		void About();

		void WorkflowItemChanged(int index) const;
	};
}}
