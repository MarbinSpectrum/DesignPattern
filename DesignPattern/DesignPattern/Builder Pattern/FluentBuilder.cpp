#include "FluentBuilder.h"

FluentBuilder::operator HtmlElement()
{
	return *root;
}

FluentBuilder::FluentBuilder(std::string root_name)
{
	root = new HtmlElement(root_name, "");
}

FluentBuilder::~FluentBuilder()
{
	if (root != NULL)
	{
		delete root;
		root = NULL;
	}
}

FluentBuilder* FluentBuilder::add_child(std::string child_name, std::string child_text)
{
	HtmlElement e(child_name, child_text);
	root->elements.emplace_back(e);
	return this;
}

std::string FluentBuilder::str() const
{
	return root->str();
}
