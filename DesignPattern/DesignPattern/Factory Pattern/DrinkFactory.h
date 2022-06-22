#pragma once

#include <map>
#include <string>
#include <iostream>
#include "HotDrinkFactory.h"

class DrinkFactory
{
private:
	std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factories;

public:
	DrinkFactory();

	std::unique_ptr<HotDrink> make_drink(const std::string& name);
};
