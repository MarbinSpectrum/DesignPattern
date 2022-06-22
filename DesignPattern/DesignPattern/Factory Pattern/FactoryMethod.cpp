#include "FactoryMethod.h"
#include <cmath>

namespace FactoryMethod
{
	Point::Point(const float x, const float y)
	: x(x)
	, y(y)
	{
	}

	Point Point::Newartesian(const float x, const float y)
	{
		return Point(x, y);
	}

	Point Point::NewPolar(const float r, const float theta)
	{
		return Point(r * cos(theta), r * sin(theta));
	}

}