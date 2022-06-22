#include "HtmlElement.h"

HtmlElement::HtmlElement()
{
}

HtmlElement::HtmlElement(const std::string& name, const std::string& text)
	: name(name)
	, text(text)
{
}

std::string HtmlElement::str() const
{
	std::string s = "";
	s += std::format("<{}>", name);
	s += std::format("{}", text);
	for (int idx = 0; idx < elements.size(); idx++)
	{
		s += elements[idx].str();
	}
	s += std::format("</{}>", name);

	return s;
}