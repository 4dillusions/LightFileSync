/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "ui_SettingsView.h"

namespace Client { namespace Controller
{
	class SettingsController;
}}

namespace Client { namespace Model
{
	class SettingsModel;
}}

namespace Client { namespace Data
{
	enum class ActionType;
}}

class QPixmap;
template <typename T1, typename T2> class QMap;

namespace Client { namespace View
{
	class SettingsView final : public QDialog
	{
		Q_OBJECT

	public:
		SettingsView(QWidget *parent, Model::SettingsModel *model);
		~SettingsView();

		void Init() const;

	private:
		Ui::SettingsView *ui;
		Controller::SettingsController *controller;
		Model::SettingsModel *model;

		QMap<Data::ActionType, QPixmap> *actionPixmapList;

	public slots:
		void LeftOnlyCboxIndexChanged(int index) const;
		void LeftNewCboxIndexChanged(int index) const;
		void RightNewCboxIndexChanged(int index) const;
		void RightOnlyCboxIndexChanged(int index) const;

		void OkClicked();
	};
}}
