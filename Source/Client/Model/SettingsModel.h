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
	class SettingsModel final
	{
		SettingsModel(const SettingsModel &) = delete;
		SettingsModel(SettingsModel &&) = delete;
		SettingsModel &operator=(const SettingsModel &) = delete;
		SettingsModel &operator=(SettingsModel &&) = delete;

		Data::WorkflowData *data = nullptr;

	public:
		SettingsModel(Data::WorkflowData *data);
		~SettingsModel() = default;

		int GetLeftOnly() const;
		void SetLeftOnly(int index) const;

		int GetLeftNew() const;
		void SetLeftNew(int index) const;

		int GetRightNew() const;
		void SetRightNew(int index) const;

		int GetRightOnly() const;
		void SetRightOnly(int index) const;

		void Save() const;
	};
}}
