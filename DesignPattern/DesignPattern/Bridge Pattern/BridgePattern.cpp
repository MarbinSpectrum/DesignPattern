#include "BridgePattern.h"
#include <iostream>
#include <format>

namespace BridgePattern
{
	void VectorRenderer::render_circle(float x, float y, float radius)
	{
		std::cout << std::format("Rasterizing circle of radius {}", radius) << std::endl;
	}

	void RasterRenderer::render_circle(float x, float y, float radius)
	{
		std::cout << std::format("Drawing a vector circle of radius {}", radius) << std::endl;
	}

	Shape::Shape(Renderer& renderer)
	: renderer(renderer)
	{
	}

	Circle::Circle(Renderer& renderer, float x, float y, float radius)
	: Shape(renderer), x(x), y(y), radius(radius)
	{
	}

	void Circle::draw()
	{
		renderer.render_circle(x, y, radius);
	}

	void Circle::resize(float factor)
	{
		radius *= factor;
	}
};
