#pragma once

namespace BridgePattern
{
	struct Renderer
	{
		//추상적인 개념
		virtual void render_circle(float x, float y, float radius) = 0;
	};

	struct VectorRenderer : Renderer
	{
		//구체적인 구현
		virtual void render_circle(float x, float y, float radius) override;
	};

	struct RasterRenderer : Renderer
	{
		//구체적인 구현
		virtual void render_circle(float x, float y, float radius) override;
	};

	struct Shape
	{
	protected:
		Renderer& renderer;
		Shape(Renderer& renderer);
	public:
		virtual void draw() = 0;
		virtual void resize(float factor) = 0;
	};

	struct Circle : Shape
	{
		float x, y, radius;

		Circle(Renderer& renderer, float x, float y, float radius);

		virtual void draw() override;
		virtual void resize(float factor) override;
	};
}
