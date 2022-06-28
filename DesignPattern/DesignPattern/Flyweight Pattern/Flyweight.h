#pragma once

#include <string>

namespace Flyweight
{
	enum class BodyType
	{
		EH_BA,
		EH_BB,
		EH_BC
	};

	enum class LensType
	{
		EH_L1,
		EH_L2,
		EH_L3
	};

	enum class LightType
	{
		LT_CLEAR,
		LT_CLOUDY,
		LT_LAMP
	};

	class Meta
	{
		static std::string bodyname[];

	};
}
