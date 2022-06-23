#include "Monostate.h"
#include <iostream>

namespace Monostate
{
	int Printer::get_id() const
	{
		return id;
	}

	void Printer::set_id(const int value)
	{
		id = value;
	}
}