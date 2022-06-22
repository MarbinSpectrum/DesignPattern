#pragma once

#include <map>
#include <string>
#include <iostream>
#include <functional>
#include "HotDrinkFactory.h"

class DrinkWithVolumeFactory
{
private:
	std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;

public:
	DrinkWithVolumeFactory();

	inline std::unique_ptr<HotDrink> make_drink(const std::string& name);
};
