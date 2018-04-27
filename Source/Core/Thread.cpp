/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "Thread.h"

namespace Core
{
	void Thread::SetRunMethod(const std::function<void()> &runMethod)
	{
		this->runMethod = runMethod;
	}

	void Thread::SetProgressPercent(int percent)
	{
		emit ProgressPercent(percent);
	}

	void Thread::SetIndexApply(int index)
	{
		emit IndexApply(index);
	}

	void Thread::SetSendObject(void *objOut)
	{
		emit SendObject(objOut);
	}

	void Thread::run()
	{
		runMethod();
		emit Finish();
	}
}
