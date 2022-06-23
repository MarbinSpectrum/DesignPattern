#include "BuilderPattern.h"

void BuilderPattern::Run()
{
	HtmlElement e = *HtmlElement::build("ul")->add_child("li", "hello")->add_child("li", "world");
	std::cout << e.str() << std::endl;
}
