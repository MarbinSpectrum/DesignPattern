#pragma once

#include <vector>

namespace Monostate
{
	class Printer
	{
		static int id;
	public:
		int get_id() const;
		void set_id(const int value);
	};
}