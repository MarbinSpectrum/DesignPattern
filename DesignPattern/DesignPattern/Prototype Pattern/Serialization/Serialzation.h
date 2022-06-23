#pragma once

#include "Serialzation.h"
#include <string>
#include <boost/serialization/access.hpp>
#include <iostream>

#define ADDRESS Serialzation::Address 
#define CONTACT Serialzation::Contact 

class Serialzation
{
	struct Address
	{
		std::string street, city;
		int suite;

	private:
		friend class boost::serialization::access;
		template<class Ar> void serialize(Ar& ar, const unsigned int version);
	};

	struct Contact
	{
		std::string name;
		Address address;

	private:
		friend class boost::serialization::access;
		template<class Ar> void serialize(Ar& ar, const unsigned int version);
	};

public:
	static void Run();
};