/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "ThreadManager.h"

namespace Core
{
	QThread *ThreadManager::GetThread()
	{
		return &thread;
	}

	void ThreadManager::SetRunMethod(const std::function<void()> &runMethod)
	{
		thread.SetRunMethod(runMethod);
	}

	void ThreadManager::SetProgressPercent(int percent)
	{
		thread.SetProgressPercent(percent);
	}

	void ThreadManager::SetIndexApply(int index)
	{
		thread.SetIndexApply(index);
	}

	void ThreadManager::SetSendObject(void *objOut)
	{
		thread.SendObject(objOut);
	}


	bool ThreadManager::GetIsCanRun() const
	{
		return isCanRun;
	}

	void ThreadManager::Start()
	{
		isCanRun = true;
		thread.start();
	}

	void ThreadManager::Stop()
	{
		isCanRun = false;
		thread.quit();
	}
}
