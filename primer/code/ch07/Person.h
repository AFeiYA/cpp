#include <string>
#include <istream>
#include <ostream>

class Person {
	public:
		Person() = default;
		Person(const std::string& name) : name(name) {}
		Person(const std::string& name, const std::string& address) : name(name), address(address) {}
		Person(std::istream& is) { read(is, *this); }
		std::string getName() const { return name; }
		std::string getAddress() const { return address; }
		std::istream& read(std::istream& is, Person& person);
		std::ostream& print(std::ostream& os, const Person& person);		// 
		std::ostream& print(std::ostream& os) const { os << name << " " << address; return os; }
	private:
		std::string name;
		std::string address;
};