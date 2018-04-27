/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace Client { namespace Model
{
	class SettingsModel;
}}

namespace Client { namespace Controller
{
	class SettingsController final
	{
		SettingsController(const SettingsController &) = delete;
		SettingsController(SettingsController &&) = delete;
		SettingsController &operator=(const SettingsController &) = delete;
		SettingsController &operator=(SettingsController &&) = delete;

		Model::SettingsModel *model;

	public:
		explicit SettingsController(Model::SettingsModel *model);
		~SettingsController() = default;

		void Save() const;
	};
}}
