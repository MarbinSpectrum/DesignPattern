#pragma once

namespace FactoryClass
{
	struct Point
	{
		float x, y;
		friend class PointFactory;

	private:
		Point(const float x, const float y);
	};

	class PointFactory
	{
	public:
		static Point Newartesian(const float x, const float y);
		static Point NewPolar(const float r, const float theta);
	};
};