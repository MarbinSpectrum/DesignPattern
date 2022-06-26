#include "StaticDecorator.h"
#include <format>
#include <iostream>

namespace StaticDecorator
{
	std::string Shape::str() const
	{
		return "";
	}

	Circle::Circle()
	{
	}

	std::string Circle::str() const
	{
		std::string s = std::format("Circle");
		return s;
	}

	template<typename T>
	ColoredShape<T>::ColoredShape(const std::string& color)
	: color(color)
	{

	}

	template <typename T>
	std::string ColoredShape<T>::str() const
	{
		std::string s = std::format("{0} has the color {1}", T::str(), color);
		return s;
	}

	void StaticDecorator::Run()
	{
		//정적 데커레이터로 색상을 가진 원 객체를 만들었다.
		//템플릿을 이용해서 컴파일 시점에 기능이 합성됬다.

		ColoredShape<Circle> colorCircle("red");
		std::cout << colorCircle.str() << std::endl;
	}
};
