#pragma once

#include <string>
#include <vector>
#include <format>
#include <iostream>
#include "HtmlElement.h"

struct HtmlSimpleBuilder
{
	HtmlElement root;

	HtmlSimpleBuilder(std::string root_name);

	void add_child(std::string child_name, std::string child_text);
	std::string str();
};

class SimpleBuilder
{
public:
	static void Run();
};