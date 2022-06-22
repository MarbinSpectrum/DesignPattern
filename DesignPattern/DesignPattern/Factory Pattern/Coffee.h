#pragma once

#include "HotDrink.h"

class Coffee : public HotDrink
{
public:
	virtual void prepare(int volume) override;
};

	
