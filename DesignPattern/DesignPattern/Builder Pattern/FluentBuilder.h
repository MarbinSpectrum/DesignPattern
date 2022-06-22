#pragma once

#include <string>
#include <vector>
#include <format>
#include <iostream>
#include "HtmlElement.h"

struct HtmlFluentBuilder
{
	HtmlElement root;

	HtmlFluentBuilder(std::string root_name);

	HtmlFluentBuilder& add_child(std::string child_name, std::string child_text);
	std::string str();
};

class FluentBuilder
{
public:
	static void Run();
};