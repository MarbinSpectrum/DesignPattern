#include "CoffeeFactory.h"
#include "../Coffee.h"

std::unique_ptr<HotDrink> CoffeeFactory::make() const
{
	return std::unique_ptr<Coffee>();
}
