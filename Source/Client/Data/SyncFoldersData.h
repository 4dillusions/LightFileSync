/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <QDataStream>

namespace Client { namespace Data
{
	struct SyncFoldersData
	{
		QString folderLeft;
		QString folderRight;

		friend QDataStream &operator << (QDataStream &out, const SyncFoldersData &syncFolders)
		{
			out << syncFolders.folderLeft;
			out << syncFolders.folderRight;

			return out;
		}

		friend QDataStream &operator >> (QDataStream &in, SyncFoldersData &syncFolders)
		{
			in >> syncFolders.folderLeft;
			in >> syncFolders.folderRight;

			return in;
		}

		bool operator == (const SyncFoldersData &value) const
		{
			return (this == &value);
		}
	};
}}
