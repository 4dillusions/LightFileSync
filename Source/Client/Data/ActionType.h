/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace Client { namespace Data
{
	enum class ActionType
	{
		Nothing = 0,
		CopyLeft = 1,
		CopyRight = 2,
		OverrideLeft = 3,
		OverrideRight = 4,
		DeleteLeft = 5,
		DeleteRight = 6,

		Apply = 7
	};
}}
