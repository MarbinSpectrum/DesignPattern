#include "ArrayByProperty.h"
#include <cmath>
#include <numeric>
#include <algorithm>

namespace ArrayByProperty
{
	int Creature::sum() const
	{
		return std::accumulate(abilities.begin(), abilities.end(), 0);
	}

	double Creature::average() const
	{
		return sum() / (double)sum();
	}

	int Creature::get_strength() const
	{
		return abilities[str];
	}

	void Creature::set_strength(int strength)
	{
		abilities[str] = strength;
	}

	int Creature::max() const
	{
		return *std::max_element(abilities.begin(), abilities.end());
	}
}