#pragma once

#include <iostream>
#include <string>

#define ADDRESS PrototypeFactory::Address 
#define CONTACT PrototypeFactory::Contact 

namespace PrototypeFactory
{
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

	struct EmployeeFactory
	{
	public:
		static CONTACT main;
		static CONTACT aux;

		static std::unique_ptr<CONTACT> NewMainOfficeEmployee(const std::string name, const int suite);
		static std::unique_ptr<CONTACT> NewAuxOfficeEmployee(const std::string name, const int suite);

	private:
		static std::unique_ptr<CONTACT> NewEmployee(const std::string name,const int suite,const CONTACT& proto);

	public:
		static void Run();
	};
};