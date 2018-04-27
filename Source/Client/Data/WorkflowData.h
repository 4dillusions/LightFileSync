/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "WorkflowItemData.h"
#include "../../Core/Serializer.h"

template <typename T1> class QList;

namespace Client { namespace Data
{
	struct WorkflowData
	{
		const QString FileName = "Workflows.dat";
		QList<WorkflowItemData> workflowList;
		WorkflowItemData *currentItem = nullptr;

		friend QDataStream &operator << (QDataStream &out, const WorkflowData &workflow)
		{
			out << workflow.workflowList;
		
			return out;
		}

		friend QDataStream &operator >> (QDataStream &in, WorkflowData &workflow)
		{
			in >> workflow.workflowList;
		
			return in;
		}

		static SyncFoldersData NewFolderPair(WorkflowItemData &item)
		{
			SyncFoldersData folders;
			folders.folderLeft = "C:";
			folders.folderRight = "D:";
			item.syncFoldersList.append(folders);

			return folders;
		}

		QString NewWorkflowItem(int index)
		{
			WorkflowItemData item;
			item.name = QString("item") + QString::number(index + 1);
			item.actionLeftOnly = ActionType::Nothing;
			item.actionLeftNew = ActionType::Nothing;
			item.actionRightNew = ActionType::Nothing;
			item.actionRightOnly = ActionType::Nothing;

			NewFolderPair(item);
			workflowList.append(item);

			return item.name;
		}

		void Load()
		{
			Core::Serializer<WorkflowData> serializer;
			this->workflowList = serializer.Deserialize(FileName).workflowList;

			if (workflowList.isEmpty())
				NewWorkflowItem(0);
		}

		void Save()
		{
			Core::Serializer<WorkflowData>::Serialize(FileName, *this);
		}
	};
}}
