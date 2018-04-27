/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "SettingsModel.h"
#include "../Data/WorkflowData.h"

using namespace Client::Data;

namespace Client { namespace Model
{
	SettingsModel::SettingsModel(WorkflowData *data) : data(data)
	{ }

	int SettingsModel::GetLeftOnly() const
	{
		return static_cast<int>(data->currentItem->actionLeftOnly);
	}

	void SettingsModel::SetLeftOnly(int index) const
	{
		data->currentItem->actionLeftOnly = static_cast<ActionType>(index);
	}

	int SettingsModel::GetLeftNew() const
	{
		return static_cast<int>(data->currentItem->actionLeftNew);
	}

	void SettingsModel::SetLeftNew(int index) const
	{
		data->currentItem->actionLeftNew = static_cast<ActionType>(index);
	}

	int SettingsModel::GetRightNew() const
	{
		return static_cast<int>(data->currentItem->actionRightNew);
	}

	void SettingsModel::SetRightNew(int index) const
	{
		data->currentItem->actionRightNew = static_cast<ActionType>(index);
	}

	int SettingsModel::GetRightOnly() const
	{
		return static_cast<int>(data->currentItem->actionRightOnly);
	}

	void SettingsModel::SetRightOnly(int index) const
	{
		data->currentItem->actionRightOnly = static_cast<ActionType>(index);
	}

	void SettingsModel::Save() const
	{
		data->Save();
	}
}}
