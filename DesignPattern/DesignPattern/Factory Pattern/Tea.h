#pragma once

#include "HotDrink.h"

class Tea : public HotDrink
{
public:
	virtual void prepare(int volume) override;
};

	
