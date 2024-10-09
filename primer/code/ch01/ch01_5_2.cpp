#include <iostream>
#include "Sales_item.h"
//1.5.2
int main() {
	//item1: 0-201-78345-x 3 20.00
	//item2: 0-201-78345-x 2 25.00
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	if (item1.isbn() == item2.isbn()) {
		std::cout << item1 + item2 << std::endl;
		return 0;
	}
	else {
		std::cerr << "Data must refer to same ISBN" << std::endl;
		return -1;
	}
}