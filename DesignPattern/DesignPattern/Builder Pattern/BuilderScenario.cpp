#include "BuilderScenario.h"

void BuilderScenario::Run()
{
	std::string words[] = { "Hello","World" };
	HtmlElement list("ul", "");
	for (auto w : words)
	{
		list.elements.emplace_back(HtmlElement("li", w));
	}
	std::cout << list.str() << std::endl;
}