#include "Coffee.h"
#include <iostream>
#include <format>

void Coffee::prepare(int volume)
{
	std::cout << std::format("Take coffee bag, boil water, pour {}ml, add some lemon", volume) << std::endl;
}

