#include "AdapterPattern.h"

namespace AdapterPattern
{
	VetorRectangle::VetorRectangle(int x, int y, int width, int height)
	{
		lines.emplace_back(Line{ Point{x,y},  Point{x + width,y} });
		lines.emplace_back(Line{ Point{x + width,y},  Point{x + width,y + height} });
		lines.emplace_back(Line{ Point{x,y},  Point{x,y + height} });
		lines.emplace_back(Line{ Point{x,y + height},  Point{x + width,y + height} });
	}

	std::vector<Line>::iterator VetorRectangle::begin()
	{
		return lines.begin();
	}

	std::vector<Line>::iterator VetorRectangle::end()
	{
		return lines.end();
	}

	//선을 점으로 바꾸는 어댑터
	LineToPointAdapter::LineToPointAdapter(Line& line)
	{
		int dist = sqrt(pow(line.start.x - line.end.x, 2) + pow(line.start.y - line.end.y, 2));
		Point dicVec = { line.end.x - line.start.x,line.end.y - line.start.y };
		int v = sqrt(pow(dicVec.x, 2) + pow(dicVec.y, 2));
		float xv = (float)dicVec.x / (float)v;
		float yv = (float)dicVec.y / (float)v;
		for (int i = 0; i < dist; i++)
		{
			points.emplace_back(Point{ line.start.x + (int)(xv * i),line.start.y + (int)(yv * i) });
		}
		points.emplace_back(Point{ line.end.x ,line.end.y });
	}

	LineToPointAdapter::Points::iterator LineToPointAdapter::begin()
	{
		return points.begin();
	}

	LineToPointAdapter::Points::iterator LineToPointAdapter::end()
	{
		return points.end();
	}
}