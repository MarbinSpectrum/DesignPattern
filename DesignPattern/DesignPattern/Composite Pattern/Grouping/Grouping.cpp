#include "Grouping.h"
#include <format>

namespace Grouping
{
	void Circle::draw()
	{
		std::cout << "Circle" << std::endl;
	}

	Group::Group(const std::string& name)
	: name(name)
	{

	}

	void Group::draw()
	{
		std::cout << std::format("Group {} contains:", name.c_str()) << std::endl;
		for (GraphicObject* o : objects)
		{
			o->draw();
		}
	}

	void GroupingTest::Run()
	{
		Group root("root");
		Circle c1, c2;
		root.objects.push_back(&c1);

		Group subgroup("sub");
		subgroup.objects.push_back(&c2);

		root.objects.push_back(&subgroup);

		root.draw();
	}
}