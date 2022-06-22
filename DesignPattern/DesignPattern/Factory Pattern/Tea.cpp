#include "Tea.h"
#include <iostream>
#include <format>

void Tea::prepare(int volume)
{
	std::cout << std::format("Take tea bag, boil water, pour {}ml, add some lemon", volume) << std::endl;
}

