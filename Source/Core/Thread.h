/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <QThread>

namespace Core
{
	class Thread final : public QThread
	{
		Q_OBJECT

			std::function<void()> runMethod;

	public:
		void SetRunMethod(const std::function<void()> &runMethod);
		void SetProgressPercent(int percent);
		void SetIndexApply(int index);
		void SetSendObject(void *objOut);

		void run() override;

	signals:
		void Finish();
		void ProgressPercent(int percent);
		void IndexApply(int index);
		void SendObject(void *objOut);
	};
}
