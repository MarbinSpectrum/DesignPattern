#include "PrototypeFactory.h"
#include "../../StudyUtility.h"

using namespace PrototypeFactory;

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

CONTACT EmployeeFactory::main = CONTACT("", new ADDRESS("123 East Dr", "London", 0));
CONTACT EmployeeFactory::aux = CONTACT("", new ADDRESS("123B East Dr", "London", 0));

////夯痢 林家
std::unique_ptr<CONTACT> EmployeeFactory::NewMainOfficeEmployee(const std::string name, const int suite)
{
	return NewEmployee(name, suite, main);
}

////瘤痢 林家
std::unique_ptr<CONTACT> EmployeeFactory::NewAuxOfficeEmployee(const std::string name, const int suite)
{
	return NewEmployee(name, suite, aux);
}

std::unique_ptr<CONTACT> EmployeeFactory::NewEmployee(const std::string name, const int suite, const CONTACT& proto)
{
	auto result = std::make_unique<CONTACT>(proto);
	result->name = name;
	result->address->suite = suite;

	return result;
}

void EmployeeFactory::Run()
{
	auto john = NewMainOfficeEmployee("John Doe", 123);
	auto jane = NewAuxOfficeEmployee("Jane Doe", 125);
}