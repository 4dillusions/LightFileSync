/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "ActionType.h"
#include "SyncFoldersData.h"

class QString;

namespace Client { namespace Data
{
	struct WorkflowItemData
	{
		QList<SyncFoldersData> syncFoldersList;
		QString name;

		ActionType actionLeftOnly;
		ActionType actionLeftNew;
		ActionType actionRightNew;
		ActionType actionRightOnly;

		friend QDataStream &operator << (QDataStream &out, const WorkflowItemData &workflowItem)
		{
			out << workflowItem.syncFoldersList;
			out << workflowItem.name;

			out << static_cast<int>(workflowItem.actionLeftOnly);
			out << static_cast<int>(workflowItem.actionLeftNew);
			out << static_cast<int>(workflowItem.actionRightNew);
			out << static_cast<int>(workflowItem.actionRightOnly);
		
			return out;
		}

		friend QDataStream &operator >> (QDataStream &in, WorkflowItemData &workflowItem)
		{
			in >> workflowItem.syncFoldersList;
			in >> workflowItem.name;

			int actionTemp;

			in >> actionTemp;
			workflowItem.actionLeftOnly = static_cast<ActionType>(actionTemp);

			in >> actionTemp;
			workflowItem.actionLeftNew = static_cast<ActionType>(actionTemp);

			in >> actionTemp;
			workflowItem.actionRightNew = static_cast<ActionType>(actionTemp);

			in >> actionTemp;
			workflowItem.actionRightOnly = static_cast<ActionType>(actionTemp);

			return in;
		}

		bool operator == (const WorkflowItemData &value) const
		{ 
			return (this == &value);
		}
	};
}}
