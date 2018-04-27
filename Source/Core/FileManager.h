/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

class QString;

namespace Core
{
	class FileManager final
	{
	public:
		static void Copy(const QString &oldPath, const QString &newPath, const QString &name, bool isFolder, bool isHidden);
		static void Delete(const QString &pathAndName, bool isFolder);
	};
}
