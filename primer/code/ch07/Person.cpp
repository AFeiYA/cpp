#include "Person.h"
#include <string>
#include <istream>
#include <ostream>

std::istream& Person::read(std::istream& is, Person& person)
{
	// TODO: insert return statement here
	is >> person.name >> person.address;
	return is;
}

std::ostream& Person::print(std::ostream& os, const Person& person)
{
	// TODO: insert return statement here
	os << person.name << " " << person.address;
	return os;
}
