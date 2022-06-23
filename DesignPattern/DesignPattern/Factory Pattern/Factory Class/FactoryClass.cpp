#include "FactoryClass.h"
#include <cmath>

namespace FactoryClass
{
	Point::Point(const float x, const float y)
	: x(x)
	, y(y)
	{
	}

	Point PointFactory::Newartesian(const float x, const float y)
	{
		return Point(x, y);
	}

	Point PointFactory::NewPolar(const float r, const float theta)
	{
		return Point(r * cos(theta), r * sin(theta));
	}

}