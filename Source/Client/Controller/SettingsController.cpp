/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "SettingsController.h"
#include "../Model/SettingsModel.h"

#include <QMessageBox>

using namespace Client::Model;

namespace Client { namespace Controller
{
	SettingsController::SettingsController(SettingsModel *model) : model(model)
	{ }

	void SettingsController::Save() const
	{
		model->Save();

		QMessageBox msgBox;
		msgBox.setText("The workflow has been saved.");
		msgBox.exec();
	}
}}
