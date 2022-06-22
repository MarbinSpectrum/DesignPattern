#include "SimpleBuilder.h"

HtmlSimpleBuilder::HtmlSimpleBuilder(std::string root_name)
{
	root.name = root_name;
}

void HtmlSimpleBuilder::add_child(std::string child_name, std::string child_text)
{
	HtmlElement e(child_name, child_text);
	root.elements.emplace_back(e);
}

std::string HtmlSimpleBuilder::str()
{
	return root.str();
}

void SimpleBuilder::Run()
{
	HtmlSimpleBuilder builder("ui");
	builder.add_child("li", "hello");
	builder.add_child("li", "world");
	std::cout << builder.str() << std::endl;
}