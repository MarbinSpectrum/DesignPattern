#pragma once

#include <string>

namespace DynamicDecorator
{
	struct Shape
	{
		virtual std::string str() const;
	};

	struct Circle : Shape
	{
		float radius;

		explicit Circle(const float radius);
		void resize(float factor);
		std::string str() const override;
	};

	struct ColoredShape : Shape
	{
		Shape& shape;
		std::string color;

		ColoredShape(Shape& shape, const std::string& color);
		std::string str() const override;
	};

	struct TransparentShape : Shape
	{
		Shape& shape;
		uint8_t transparency;

		TransparentShape(Shape& shape, const uint8_t transparency);
		std::string str() const override;
	};

	struct DynamicDecorator
	{
		static void Run();
	};
}
