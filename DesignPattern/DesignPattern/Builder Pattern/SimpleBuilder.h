#pragma once

#include <string>
#include <vector>
#include <format>
#include <iostream>
#include "HtmlElement.h"

class HtmlElement;

class SimpleBuilder
{
private:
	HtmlElement* root;

public:
	SimpleBuilder(std::string root_name);
	~SimpleBuilder();

	void		add_child(std::string child_name, std::string child_text);
	std::string str() const;
};