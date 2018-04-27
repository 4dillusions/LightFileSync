/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <functional>

namespace Core
{
	/*
	Static IOC for Logging etc.
	Ioc implements prototype, factory and singleton patterns together, called Inversion Of Control and Dependency Injection pattern (DI)
	This Ioc supports one instance -> one prototype implementation
	*/
	template <typename TInstance> class Ioc final
	{
	public:
		Ioc() = delete;
		Ioc(const Ioc &) = delete;
		Ioc(Ioc &&) = delete;
		Ioc &operator=(const Ioc &) = delete;
		Ioc &operator=(Ioc &&) = delete;
		~Ioc() = delete;

		static TInstance &Get()
		{
			static TInstance instance;

			return instance;
		}
	};

	/*
	Dynamic IOC for subsystems and other dynamic main objects
	Ioc implements prototype, factory and singleton patterns together, called Inversion Of Control and Dependency Injection pattern (DI)
	This Ioc supports one instance -> one prototype implementation
	*/
	template <typename TInstance> class Ioc<TInstance *> final
	{
		static TInstance *instance;
		static std::function<TInstance *()> prototype;

	public:
		Ioc() = delete;
		Ioc(const Ioc &) = delete;
		Ioc(Ioc &&) = delete;
		Ioc &operator=(const Ioc &) = delete;
		Ioc &operator=(Ioc &&) = delete;

		template <typename TType> static void Register()
		{
			if (prototype == nullptr && instance == nullptr)
				prototype = []() { return new TType; };
		}

		template <typename TType> static void Register(const std::function<TInstance *()> &prototype)
		{
			if (prototype != nullptr && Ioc<TInstance *>::prototype == nullptr && instance == nullptr)
				Ioc<TInstance *>::prototype = prototype;
		}

		static void Create()
		{
			if (prototype != nullptr && instance == nullptr)
				instance = prototype();
		}

		static void Release()
		{
			delete instance;
			prototype = nullptr;
		}

		static TInstance *Get()
		{
			return instance;
		}

		static bool IsExist()
		{
			return instance != nullptr;
		}
	};

	template <typename TInstance> TInstance *Ioc<TInstance *>::instance = nullptr;
	template <typename TInstance> std::function<TInstance *()> Ioc<TInstance *>::prototype = nullptr;
}
