#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace Grouping
{
	struct GraphicObject
	{
		virtual void draw() = 0;
	};

	struct Circle : GraphicObject
	{
		virtual void draw() override;
	};

	struct Group : GraphicObject
	{
		std::string name;

		explicit Group(const std::string& name);
		virtual void draw() override;

		std::vector<GraphicObject*> objects;
	};

	struct GroupingTest
	{
		static void Run();
	};
};