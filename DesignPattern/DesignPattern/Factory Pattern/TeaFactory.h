#pragma once

#include "HotDrinkFactory.h"

class TeaFactory : public HotDrinkFactory
{
public :
	virtual std::unique_ptr<HotDrink> make() const override;
};

	
