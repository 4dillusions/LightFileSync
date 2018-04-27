/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace Client { namespace Data
{
	enum class ActionType;
	enum class CategoryType;
}}

class QPixmap;
class QIcon;
template <typename T1, typename T2> class QMap;

namespace Client { namespace View
{
	class ResourceFactory final
	{
		ResourceFactory() = delete;
		~ResourceFactory() = delete;
		ResourceFactory(const ResourceFactory &) = delete;
		ResourceFactory(ResourceFactory &&) = delete;
		ResourceFactory &operator=(const ResourceFactory &) = delete;
		ResourceFactory &operator=(ResourceFactory &&) = delete;

	public:
		static QMap<Data::ActionType, QPixmap> *CreateActionPixmapList();
		static QMap<Data::ActionType, QIcon> *ResourceFactory::CreateActionIconList();
		static QMap<Data::CategoryType, QIcon> *ResourceFactory::CreateCategoryIconList();
	};
}}
