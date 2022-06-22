#pragma once

#include <string>
#include <vector>
#include <format>
#include <iostream>

struct HtmlElement
{
	std::string name;
	std::string text;
	std::vector<HtmlElement> elements;

	//static std::unique_ptr<HtmlFluentBuilder> build(const std::string& root_name);

	HtmlElement();
	HtmlElement(const std::string& name, const std::string& text);

	std::string str() const;
};