#pragma once

#include <string>
#include <vector>
#include <format>
#include <iostream>
#include "HtmlElement.h"

class HtmlElement;

class FluentBuilder
{
private:
	HtmlElement* root;

public:
	operator HtmlElement();

	FluentBuilder(std::string root_name);
	~FluentBuilder();

	FluentBuilder*	add_child(std::string child_name, std::string child_text);
	std::string		str() const;
};