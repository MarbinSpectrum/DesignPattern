#include "SimpleBuilder.h"

SimpleBuilder::SimpleBuilder(std::string root_name)
{
	root = new HtmlElement(root_name, "");
}

SimpleBuilder::~SimpleBuilder()
{
	if (root != NULL)
	{
		delete root;
		root = NULL;
	}
}

void SimpleBuilder::add_child(std::string child_name, std::string child_text)
{
	HtmlElement e(child_name, child_text);
	root->elements.emplace_back(e);
}

std::string SimpleBuilder::str() const
{
	return root->str();
}