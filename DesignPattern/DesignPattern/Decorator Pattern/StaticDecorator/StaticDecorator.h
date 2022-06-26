#pragma once

#include <string>
#include <format>


namespace StaticDecorator
{
	struct Shape
	{
		virtual std::string str() const;
	};

	struct Circle : Shape
	{
		Circle();
		std::string str() const override;
	};

	template <typename T> struct ColoredShape : T
	{
		static_assert(std::is_base_of<Shape, T>::value, "Shape ��ü�� ��ӹ޾ƾ��մϴ�.");

		ColoredShape(const std::string& color);

		std::string color;

		std::string str() const override;
	};

	struct StaticDecorator
	{
		static void Run();
	};
}
