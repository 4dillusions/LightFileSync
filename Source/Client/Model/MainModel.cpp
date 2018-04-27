/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "MainModel.h"
#include "../Data/WorkflowData.h"
#include "../../Core/Tuple.h"

using namespace Client::Data;
using namespace Core;

namespace Client { namespace Model
{
	MainModel::MainModel(WorkflowData *data)
	{
		this->data = data;

		this->data->Load();
		this->data->currentItem = &this->data->workflowList.first();
	}

	QStringList MainModel::GetWorkflowItemList() const
	{
		QStringList result;

		for (auto item : data->workflowList)
			result.append(item.name);

		return result;
	}

	void MainModel::SetWorkflowItemIndex(int index) const
	{
		if (data->workflowList.length() > index)
			data->currentItem = &data->workflowList[index];
	}

	void MainModel::SetWorkflowItemText(const QString &text) const
	{
		data->currentItem->name = text;
	}

	void MainModel::Save() const
	{
		data->Save();
	}

	QList<SyncFoldersData> MainModel::GetFolderItemList() const
	{
		QList<SyncFoldersData> result;

		for (const auto folders : data->currentItem->syncFoldersList)
			result.append(SyncFoldersData{ folders.folderLeft, folders.folderRight });

		return result;
	}

	void MainModel::SetFolderItemTexts(int index, Tuple2<QString, QString> texts) const
	{
		if (data->currentItem->syncFoldersList.count() > index)
		{
			if (!texts.item1.isEmpty())
				data->currentItem->syncFoldersList[index].folderLeft = texts.item1;
		
			if (!texts.item2.isEmpty())
				data->currentItem->syncFoldersList[index].folderRight = texts.item2;
		}
	}

	void MainModel::DeleteCurrentWorkflowItem() const
	{
		data->workflowList.removeAt(data->workflowList.indexOf(*data->currentItem));
		data->currentItem = &data->workflowList.first();
	}

	QString MainModel::AddNewWorkflowItem(int index) const
	{
		return data->NewWorkflowItem(index);
	}

	SyncFoldersData MainModel::NewFolderPair() const
	{
		return data->NewFolderPair(*data->currentItem);
	}

	void MainModel::DeleteFolderPair(int index) const
	{
		data->currentItem->syncFoldersList.removeAt(index);
	}
}}
