/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "ui_AboutView.h"

namespace Client { namespace View
{
	class AboutView  final : public QDialog
	{
		Q_OBJECT

	public:
		AboutView(QWidget *parent = Q_NULLPTR);
		~AboutView();

	private:
		Ui::AboutView *ui;
	};
}}
