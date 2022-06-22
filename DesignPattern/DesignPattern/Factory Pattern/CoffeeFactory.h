#pragma once

#include "HotDrinkFactory.h"

class CoffeeFactory : public HotDrinkFactory
{
public :
	virtual std::unique_ptr<HotDrink> make() const override;
};

	
