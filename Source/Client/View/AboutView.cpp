/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "AboutView.h"

namespace Client { namespace View
{
	AboutView::AboutView(QWidget *parent)
		: QDialog(parent)
	{
		ui = new Ui::AboutView();
		ui->setupUi(this);

		setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
	}

	AboutView::~AboutView()
	{
		delete ui;
	}
}}
