#include "Serialzation.h"

template<class Ar>
void ADDRESS::serialize(Ar& ar, const unsigned int version)
{
	//데이터를 비트열로 기록
	ar & street;
	ar & city;
	ar & suite;
}

template<class Ar>
void CONTACT::serialize(Ar& ar, const unsigned int version)
{
	//데이터를 비트열로 기록
	ar & name;
	ar & address;
}


void Serialzation::Run()
{
	CONTACT worker{ "", ADDRESS{"123 East Dr", "London", 0 } };

	CONTACT john = worker;
	john.name = "John Doe";
	john.address.suite = 10;

	CONTACT jane = worker;
	jane.name = "Jane Doe";
	jane.address.suite = 11;
}
