/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "SettingsView.h"
#include "../Model/SettingsModel.h"
#include "../Controller/SettingsController.h"
#include "../Data/ActionType.h"
#include "ResourceFactory.h"

using namespace Client::Model;
using namespace Client::Controller;
using namespace Client::Data;

namespace Client { namespace View
{
	SettingsView::SettingsView(QWidget *parent, SettingsModel *model)
		: QDialog(parent), model(model)
	{
		ui = new Ui::SettingsView;
		ui->setupUi(this);

		setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

		ui->LeftOnlyCbox->setItemData(static_cast<int>(ActionType::CopyRight), Qt::NoItemFlags, Qt::UserRole - 1);
		ui->LeftOnlyCbox->setItemData(static_cast<int>(ActionType::OverrideLeft), Qt::NoItemFlags, Qt::UserRole - 1);
		ui->LeftOnlyCbox->setItemData(static_cast<int>(ActionType::OverrideRight), Qt::NoItemFlags, Qt::UserRole - 1);
		ui->LeftOnlyCbox->setItemData(static_cast<int>(ActionType::DeleteRight), Qt::NoItemFlags, Qt::UserRole - 1);

		ui->LeftNewCbox->setItemData(static_cast<int>(ActionType::CopyLeft), Qt::NoItemFlags, Qt::UserRole - 1);
		ui->LeftNewCbox->setItemData(static_cast<int>(ActionType::CopyRight), Qt::NoItemFlags, Qt::UserRole - 1);

		ui->RightNewCbox->setItemData(static_cast<int>(ActionType::CopyLeft), Qt::NoItemFlags, Qt::UserRole - 1);
		ui->RightNewCbox->setItemData(static_cast<int>(ActionType::CopyRight), Qt::NoItemFlags, Qt::UserRole - 1);

		ui->RightOnlyCbox->setItemData(static_cast<int>(ActionType::CopyLeft), Qt::NoItemFlags, Qt::UserRole - 1);
		ui->RightOnlyCbox->setItemData(static_cast<int>(ActionType::OverrideLeft), Qt::NoItemFlags, Qt::UserRole - 1);
		ui->RightOnlyCbox->setItemData(static_cast<int>(ActionType::OverrideRight), Qt::NoItemFlags, Qt::UserRole - 1);
		ui->RightOnlyCbox->setItemData(static_cast<int>(ActionType::DeleteLeft), Qt::NoItemFlags, Qt::UserRole - 1);

		ui->LeftOnlyLabel->setAlignment(Qt::AlignCenter);
		ui->LeftNewLabel->setAlignment(Qt::AlignCenter);
		ui->RightNewLabel->setAlignment(Qt::AlignCenter);
		ui->RightOnlyLabel->setAlignment(Qt::AlignCenter);

		controller = new SettingsController(model);

		actionPixmapList = ResourceFactory::CreateActionPixmapList();
	}

	SettingsView::~SettingsView()
	{
		//delete model; //delete in MainView dtor
		delete controller;
		delete ui;
	}

	void SettingsView::Init() const
	{
		ui->LeftOnlyCbox->setCurrentIndex(static_cast<int>(model->GetLeftOnly()));
		ui->LeftNewCbox->setCurrentIndex(static_cast<int>(model->GetLeftNew()));
		ui->RightNewCbox->setCurrentIndex(static_cast<int>(model->GetRightNew()));
		ui->RightOnlyCbox->setCurrentIndex(static_cast<int>(model->GetRightOnly()));

		ui->LeftOnlyLabel->setPixmap((*actionPixmapList)[(ActionType)model->GetLeftOnly()]);
		ui->LeftNewLabel->setPixmap((*actionPixmapList)[(ActionType)model->GetLeftNew()]);
		ui->RightNewLabel->setPixmap((*actionPixmapList)[(ActionType)model->GetRightNew()]);
		ui->RightOnlyLabel->setPixmap((*actionPixmapList)[(ActionType)model->GetRightOnly()]);
	}

	void SettingsView::LeftOnlyCboxIndexChanged(int index) const
	{
		ui->LeftOnlyLabel->setPixmap((*actionPixmapList)[(ActionType)index]);
	}

	void SettingsView::LeftNewCboxIndexChanged(int index) const
	{
		ui->LeftNewLabel->setPixmap((*actionPixmapList)[(ActionType)index]);
	}

	void SettingsView::RightNewCboxIndexChanged(int index) const
	{
		ui->RightNewLabel->setPixmap((*actionPixmapList)[(ActionType)index]);
	}

	void SettingsView::RightOnlyCboxIndexChanged(int index) const
	{
		ui->RightOnlyLabel->setPixmap((*actionPixmapList)[(ActionType)index]);
	}

	void SettingsView::OkClicked()
	{
		model->SetLeftOnly(ui->LeftOnlyCbox->currentIndex());
		model->SetLeftNew(ui->LeftNewCbox->currentIndex());
		model->SetRightNew(ui->RightNewCbox->currentIndex());
		model->SetRightOnly(ui->RightOnlyCbox->currentIndex());

		controller->Save();
		close();
	}
}}
