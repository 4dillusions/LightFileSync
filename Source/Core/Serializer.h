/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <QFile>

namespace Core
{
	template <typename TData> class Serializer final
	{
	public:
		static void Serialize(const QString &name, TData &data)
		{
			QFile file(name);
			file.open(QIODevice::WriteOnly);

			QDataStream out(&file);
			out << data;

			file.close();
		}

		static TData Deserialize(const QString &name)
		{
			TData resultData;

			QFile file(name);
			if (file.exists())
				file.open(QIODevice::ReadOnly);
			else
			{
				file.close();
				Serialize(name, resultData);

				return resultData;
			}

			QDataStream in(&file);
			in >> resultData;

			file.close();

			return resultData;
		}
	};
}
