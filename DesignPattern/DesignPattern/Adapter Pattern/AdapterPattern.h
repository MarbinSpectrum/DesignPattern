#pragma once

#include "AdapterPattern.h"
#include <vector>
#include <math.h>

namespace AdapterPattern
{
	struct Point
	{
		int x, y;
	};

	struct Line
	{
		Point start, end;
	};

	struct VectorObject
	{
		virtual std::vector<Line>::iterator begin() = 0;
		virtual std::vector<Line>::iterator end() = 0;
	};

	struct VetorRectangle : VectorObject
	{
		VetorRectangle(int x, int y, int width, int height);
		std::vector<Line>::iterator begin() override;
		std::vector<Line>::iterator end() override;

	private:
		std::vector<Line> lines;
	};

	struct LineToPointAdapter
	{
		typedef std::vector<Point> Points;

		LineToPointAdapter(Line& line);

		virtual Points::iterator begin();
		virtual Points::iterator end();

	private:
		Points points;
	};
};
