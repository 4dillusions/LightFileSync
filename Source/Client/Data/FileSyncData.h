/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "FileData.h"

namespace Client { namespace Data
{
	enum class ActionType;

	struct FileSyncData
	{
		FileData leftFile; //56 bytes
		FileData rightFile; //56 bytes

		QString folderLeft; //8 bytes
		QString folderRight; //8 bytes

		ActionType action; //4 bytes
		CategoryType category; //4 bytes
	};
}}
