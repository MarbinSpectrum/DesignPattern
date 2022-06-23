#pragma once

#include <iostream>
#include "../HotDrink.h"

class HotDrinkFactory
{
public:
	virtual std::unique_ptr<HotDrink> make() const = 0;
};

	
