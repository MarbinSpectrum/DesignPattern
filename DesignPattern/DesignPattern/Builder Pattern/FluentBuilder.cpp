#include "FluentBuilder.h"

HtmlFluentBuilder::HtmlFluentBuilder(std::string root_name)
{
	root.name = root_name;
}

HtmlFluentBuilder& HtmlFluentBuilder::add_child(std::string child_name, std::string child_text)
{
	HtmlElement e(child_name, child_text);
	root.elements.emplace_back(e);
	return *this;
}

std::string HtmlFluentBuilder::str()
{
	return root.str();
}

void FluentBuilder::Run()
{
	HtmlFluentBuilder builder("ui");
	builder.add_child("li", "hello").add_child("li", "world");
	std::cout << builder.str() << std::endl;
}