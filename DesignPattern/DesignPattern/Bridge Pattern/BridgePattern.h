#pragma once

namespace BridgePattern
{
	struct Renderer
	{
		//�߻����� ����
		virtual void render_circle(float x, float y, float radius) = 0;
	};

	struct VectorRenderer : Renderer
	{
		//��ü���� ����
		virtual void render_circle(float x, float y, float radius) override;
	};

	struct RasterRenderer : Renderer
	{
		//��ü���� ����
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
