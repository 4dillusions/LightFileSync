/*
Light File Sync
Copyright (c) 2011-2018 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace Core
{
	template <typename T1> class Tuple1 final
	{
	public:
		T1 item1;

		Tuple1(T1 item1) : item1(item1)
		{ }
	};

	template <typename T1, typename T2> class Tuple2 final
	{
	public:
		T1 item1;
		T2 item2;

		Tuple2(T1 item1, T2 item2) : item1(item1), item2(item2)
		{ }
	};

	template <typename T1, typename T2, typename T3> class Tuple3 final
	{
	public:
		T1 item1;
		T2 item2;
		T3 item3;

		Tuple3(T1 item1, T2 item2, T3 item3) : item1(item1), item2(item2), item3(item3)
		{ }
	};

	template <typename T1, typename T2, typename T3, typename T4> class Tuple4 final
	{
	public:
		T1 item1;
		T2 item2;
		T3 item3;
		T4 item4;

		Tuple4(T1 item1, T2 item2, T3 item3, T4 item4) : item1(item1), item2(item2), item3(item3), item4(item4)
		{ }
	};

	template <typename T1, typename T2, typename T3, typename T4, typename T5> class Tuple5 final
	{
	public:
		T1 item1;
		T2 item2;
		T3 item3;
		T4 item4;
		T5 item5;

		Tuple5(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5) : item1(item1), item2(item2), item3(item3), item4(item4), item5(item5)
		{ }
	};

	class Tuple final
	{
		Tuple() = delete;
		Tuple(const Tuple &) = delete;
		Tuple(Tuple &&) = delete;
		Tuple &operator=(const Tuple &) = delete;
		Tuple &operator=(Tuple &&) = delete;
		~Tuple() = delete;

	public:
		template <typename T1> static Tuple1<T1> Create(T1 item1)
		{
			return Tuple1<T1>(item1);
		}

		template <typename T1, typename T2> static Tuple2<T1, T2> Create(T1 item1, T2 item2)
		{
			return Tuple2<T1, T2>(item1, item2);
		}

		template <typename T1, typename T2, typename T3> static Tuple3<T1, T2, T3> Create(T1 item1, T2 item2, T3 item3)
		{
			return Tuple3<T1, T2, T3>(item1, item2, item3);
		}

		template <typename T1, typename T2, typename T3, typename T4> static Tuple4<T1, T2, T3, T4> Create(T1 item1, T2 item2, T3 item3, T4 item4)
		{
			return Tuple4<T1, T2, T3, T4>(item1, item2, item3, item4);
		}

		template <typename T1, typename T2, typename T3, typename T4, typename T5> static Tuple5<T1, T2, T3, T4, T5> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5)
		{
			return Tuple5<T1, T2, T3, T4, T5>(item1, item2, item3, item4, item5);
		}
	};
}
