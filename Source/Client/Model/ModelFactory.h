/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace Client { namespace Data
{
	struct WorkflowData;
}}

namespace Client { namespace Model
{
	class MainModel;
	class SettingsModel;
}}

namespace Client { namespace Model
{
	class ModelFactory final
	{
		ModelFactory() = delete;
		~ModelFactory() = delete;
		ModelFactory(const ModelFactory &) = delete;
		ModelFactory(ModelFactory &&) = delete;
		ModelFactory &operator=(const ModelFactory &) = delete;
		ModelFactory &operator=(ModelFactory &&) = delete;
	
		static Data::WorkflowData *GetWorkflowData();

	public:
		static MainModel *CreateMainModel();
		static SettingsModel *CreateSettingsModel();
	};
}}
