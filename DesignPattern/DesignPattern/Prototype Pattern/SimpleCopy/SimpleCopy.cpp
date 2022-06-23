#include "SimpleCopy.h"

void SimpleCopy::Run()
{
	CONTACT worker{ "", ADDRESS{"123 East Dr", "London", 0 }};

	CONTACT john = worker;
	john.name = "John Doe";
	john.address.suite = 10;

	CONTACT jane = worker;
	jane.name = "Jane Doe";
	jane.address.suite = 11;
}
