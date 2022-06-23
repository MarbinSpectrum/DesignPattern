#pragma once

#include "CopyConstructor.h"
#include <string>

#define ADDRESS CopyConstructor::Address 
#define CONTACT CopyConstructor::Contact 

class CopyConstructor
{
public:
	struct Address
	{
		std::string street, city;
		int suite;

		Address(const std::string& street, const std::string& city, const int suite);

		Address& operator=(const Address& other);
		Address* Clone();
	};

	struct Contact
	{
		std::string name;
		Address* address;

		Contact(const Contact& other);
		Contact(const std::string& name, Address* address);

		Contact& operator=(const Contact& other);
		Contact* Clone();
	};

	static void Run();
};
