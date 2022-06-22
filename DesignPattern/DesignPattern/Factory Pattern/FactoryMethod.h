#pragma once

namespace FactoryMethod
{
	struct Point
	{
		float x, y;

	protected:
		Point(const float x, const float y);

		//팩토리 매서드
	public:
		static Point Newartesian(const float x, const float y);
		static Point NewPolar(const float r, const float theta);
	};
};