#include "CopyConstructor.h"
#include "../../StudyUtility.h"

ADDRESS::Address(const std::string& street, const std::string& city, const int suite)
	: street(street)
	, city(city)
	, suite(suite)
{
}

ADDRESS& ADDRESS::operator=(const ADDRESS& other)
{
	if (this == &other)
	{
		return *this;
	}

	street = other.street;
	city = other.city;
	suite = other.suite;

	return *this;
}

ADDRESS* ADDRESS::Clone()
{
	return new ADDRESS(*this);
}

CONTACT::Contact(const CONTACT& other)
: name(other.name)
, address(new ADDRESS(*other.address))
{

}

CONTACT::Contact(const std::string& name, ADDRESS* address)
	: name(name)
	, address(address)
{
}

CONTACT& CONTACT::operator=(const CONTACT& other)
{
	if (this == &other)
	{
		return *this;
	}

	name = other.name;

	SAFE_DELETE(address);
	address = other.address;

	return *this;
}

CONTACT* CONTACT::Clone()
{
	return new CONTACT(*this);
}


void CopyConstructor::Run()
{
	CONTACT worker("", new ADDRESS("123 East Dr", "London", 0));

	CONTACT john = worker;
	john.name = "John Doe";
	john.address->suite = 10;

	CONTACT jane = worker;
	jane.name = "Jane Doe";
	jane.address->suite = 11;
}
