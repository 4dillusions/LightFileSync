/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "FileManager.h"

#include "windows.h"

#include <QDir>
#include <QFile>

namespace Core
{
	void FileManager::Copy(const QString &oldPath, const QString &newPath, const QString &name, bool isFolder, bool isHidden)
	{
		const QString oldPathAndName = oldPath + name;
		const QString newPathAndName = newPath + name;

		if (isFolder)
		{
			QDir folder(newPathAndName);
			if (!folder.exists())
			{
				folder.mkdir(newPathAndName);

				if (isHidden && folder.exists())
					SetFileAttributes(reinterpret_cast<LPCWSTR>(newPathAndName.utf16()), FILE_ATTRIBUTE_HIDDEN); //there isn't platform independent solution in QT
			}
		}
		else
		{
			QFile newFile(newPathAndName);
			if (newFile.exists())
			{
				newFile.setPermissions(QFile::ReadOther | QFile::WriteOther);
				newFile.remove();
			}

			QFile oldFile(oldPathAndName);
			oldFile.copy(newPathAndName);
		}
	}

	void FileManager::Delete(const QString &pathAndName, bool isFolder)
	{
		if (isFolder)
		{
			QDir folder(pathAndName);
			if (folder.exists())
			{
				SetFileAttributes(reinterpret_cast<LPCWSTR>(pathAndName.utf16()), FILE_ATTRIBUTE_NORMAL); //there isn't platform independent solution in QT
				folder.removeRecursively();
			}
		}
		else
		{
			QFile file(pathAndName);
			if (file.exists())
			{
				file.setPermissions(QFile::ReadOther | QFile::WriteOther);
				file.remove();
			}
		}
	}
}
