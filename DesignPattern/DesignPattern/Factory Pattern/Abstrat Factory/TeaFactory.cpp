#include "TeaFactory.h"
#include "../Tea.h"

std::unique_ptr<HotDrink> TeaFactory::make() const
{
	return std::unique_ptr<Tea>();
}
