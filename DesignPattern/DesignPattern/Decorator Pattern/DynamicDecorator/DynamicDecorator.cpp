#include "DynamicDecorator.h"
#include <format>
#include <iostream>

namespace DynamicDecorator
{
	std::string Shape::str() const
	{
		return "";
	}

	Circle::Circle( const float radius)
	: radius(radius)
	{

	}

	std::string Circle::str() const
	{
		std::string s = std::format("Circle\nRadius : {0}\n", radius);
		return s;
	}

	ColoredShape::ColoredShape(Shape& shape, const std::string& color)
	: shape(shape)
	, color(color)
	{
	}

	std::string ColoredShape::str() const
	{
		std::string s = std::format("{0}Color : {1}\n", shape.str(), color);
		return s;
	}

	TransparentShape::TransparentShape(Shape& shape, const uint8_t transparency)
	: shape(shape)
	, transparency(transparency)
	{
	}

	std::string TransparentShape::str() const
	{
		std::string s = std::format("{0}Alpha : {1}%\n", shape.str(), (static_cast<float>(transparency) / 255.f)*100.f);
		return s;
	}

	void DynamicDecorator::Run()
	{
		//동적 데커레이터로 투명도와 색상을 가진 원 객체를 만들었다.
		//동적으로 필요할때마다 코드로 추가

		Circle circle{ 23 };
		ColoredShape coloredShape{ circle, "red" };
		TransparentShape transShape{ coloredShape, 85 };

		std::cout << transShape.str() << std::endl;
	}
	
};
