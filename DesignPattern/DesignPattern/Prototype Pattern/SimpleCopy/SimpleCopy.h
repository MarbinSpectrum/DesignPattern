#pragma once

#include "SimpleCopy.h"
#include <string>

#define ADDRESS SimpleCopy::Address 
#define CONTACT SimpleCopy::Contact 

class SimpleCopy
{
	struct Address
	{
		std::string street, city;
		int suite;
	};

	struct Contact
	{
		std::string name;
		Address address;
	};

public:
	static void Run();
};
