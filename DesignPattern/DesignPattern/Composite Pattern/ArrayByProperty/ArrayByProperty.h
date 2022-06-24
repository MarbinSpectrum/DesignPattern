#pragma once

#include <array>

namespace ArrayByProperty
{
	class Creature
	{
		enum Abilities { str, agl, intl, count };
		std::array<int, count> abilities;

	public:
		int sum() const;
		double average() const;
		int get_strength() const;
		void set_strength(int strength);
		int max() const;
	};
};