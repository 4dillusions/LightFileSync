/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <QDateTime>

namespace Client { namespace Data
{
	struct FileData
	{
		QString relativeFolder; //8 bytes
		QString relativeFolderAndName; //8 bytes
		QString name; //8 bytes

		QDateTime modifiedTime; //8 bytes
		qint64 fileSize = 0; //8 bytes
		QString fileSizeStat; //8 bytes

		bool isFolder = false; //1 byte
		bool isHidden = false; //1 byte
		bool isSymlink = false; //1 byte

		bool operator == (const FileData &value) const
		{
			if (fileSize == 0 && isSymlink == false)
				return relativeFolderAndName == value.relativeFolderAndName;

			return relativeFolderAndName == value.relativeFolderAndName && fileSize == value.fileSize && modifiedTime == value.modifiedTime;
		}
	};
}}
