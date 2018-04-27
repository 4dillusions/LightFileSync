/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "ModelFactory.h"
#include "../Data/WorkflowData.h"
#include "MainModel.h"
#include "SettingsModel.h"

using namespace Client::Data;

namespace Client { namespace Model
{
	WorkflowData *ModelFactory::GetWorkflowData()
	{
		static WorkflowData data;
		return &data;
	}

	MainModel *ModelFactory::CreateMainModel()
	{
		return new MainModel(GetWorkflowData());
	}

	SettingsModel *ModelFactory::CreateSettingsModel()
	{
		return new SettingsModel(GetWorkflowData());
	}
}}
