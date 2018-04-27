/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "ResourceFactory.h"
#include "../Data/ActionType.h"
#include "../Data/CategoryType.h"

#include <QMap>
#include <QIcon>

using namespace Client::Data;

namespace Client { namespace View
{
	QMap<ActionType, QPixmap> *ResourceFactory::CreateActionPixmapList()
	{
		static QMap<ActionType, QPixmap> result;

		if (result.isEmpty())
		{
			result.insert(ActionType::Nothing, QPixmap(":/MainView/Resources/nothing.png"));
			result.insert(ActionType::CopyLeft, QPixmap(":/MainView/Resources/copyLeft.png"));
			result.insert(ActionType::CopyRight, QPixmap(":/MainView/Resources/copyRight.png"));
			result.insert(ActionType::OverrideLeft, QPixmap(":/MainView/Resources/overrideLeft.png"));
			result.insert(ActionType::OverrideRight, QPixmap(":/MainView/Resources/overrideRight.png"));
			result.insert(ActionType::DeleteLeft, QPixmap(":/MainView/Resources/deleteLeft.png"));
			result.insert(ActionType::DeleteRight, QPixmap(":/MainView/Resources/deleteRight.png"));

			result.insert(ActionType::Apply, QPixmap(":/MainView/Resources/apply.png"));
		}

		return &result;
	}

	QMap<ActionType, QIcon> *ResourceFactory::CreateActionIconList()
	{
		static QMap<ActionType, QIcon> result;

		if (result.isEmpty())
		{
			result.insert(ActionType::Nothing, QIcon(":/MainView/Resources/nothing.png"));
			result.insert(ActionType::CopyLeft, QIcon(":/MainView/Resources/copyLeft.png"));
			result.insert(ActionType::CopyRight, QIcon(":/MainView/Resources/copyRight.png"));
			result.insert(ActionType::OverrideLeft, QIcon(":/MainView/Resources/overrideLeft.png"));
			result.insert(ActionType::OverrideRight, QIcon(":/MainView/Resources/overrideRight.png"));
			result.insert(ActionType::DeleteLeft, QIcon(":/MainView/Resources/deleteLeft.png"));
			result.insert(ActionType::DeleteRight, QIcon(":/MainView/Resources/deleteRight.png"));

			result.insert(ActionType::Apply, QIcon(":/MainView/Resources/apply.png"));
		}

		return &result;
	}

	QMap<CategoryType, QIcon>* ResourceFactory::CreateCategoryIconList()
	{
		static QMap<CategoryType, QIcon> result;

		if (result.isEmpty())
		{
			result.insert(CategoryType::LeftOnly, QIcon(":/MainView/Resources/LeftOnly.png"));
			result.insert(CategoryType::LeftNew, QIcon(":/MainView/Resources/LeftNew.png"));
			result.insert(CategoryType::RightNew, QIcon(":/MainView/Resources/RightNew.png"));
			result.insert(CategoryType::RightOnly, QIcon(":/MainView/Resources/RightOnly.png"));
		}

		return &result;
	}
}}
