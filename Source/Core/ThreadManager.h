/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "Thread.h"

class QThread;

namespace Core
{
	class ThreadManager final
	{
		Thread thread;
		bool isCanRun = false;

	public:
		QThread * GetThread();
		void SetRunMethod(const std::function<void()> &runMethod);
		void SetProgressPercent(int percent);
		void SetIndexApply(int index);
		void SetSendObject(void *objOut);
		bool GetIsCanRun() const;

		void Start();
		void Stop();
	};
}
