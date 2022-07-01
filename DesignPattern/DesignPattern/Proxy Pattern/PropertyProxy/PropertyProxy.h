#pragma once

namespace PropertyProxy
{
	template<typename T> struct Property
	{
		T value;
		Property(const T initial_value);
		operator T();
		T operator =(T new_value);
	};

	struct Creature
	{
		Property<int> strength{ 10 };
		Property<int> agility{ 5 };
	};

	struct PropertyProxy
	{
		static void Run();
	};
}
