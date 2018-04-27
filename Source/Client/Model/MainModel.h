/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "../Data/SyncFoldersData.h"

namespace Core
{
	template <typename T1, typename T2> class Tuple2;
}

namespace Client { namespace Data
{
	struct WorkflowData;
}}

template <typename T1> class QList;

namespace Client { namespace Model
{
	class MainModel final
	{
		MainModel(const MainModel &) = delete;
		MainModel(MainModel &&) = delete;
		MainModel &operator=(const MainModel &) = delete;
		MainModel &operator=(MainModel &&) = delete;

		Data::WorkflowData *data;

	public:
		MainModel(Data::WorkflowData *data);
		~MainModel() = default;

		QStringList GetWorkflowItemList() const;
		void SetWorkflowItemIndex(int index) const;
		void SetWorkflowItemText(const QString &text) const;

		QList<Data::SyncFoldersData> GetFolderItemList() const;
		void SetFolderItemTexts(int index, Core::Tuple2<QString, QString> texts) const;

		void DeleteCurrentWorkflowItem() const;
		QString AddNewWorkflowItem(int index) const;
		Data::SyncFoldersData NewFolderPair() const;
		void DeleteFolderPair(int index) const;

		void Save() const;
	};
}}
