#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item book;
	// read ISBN, number of copies sold, and sales price
	//0-201-7353-x 4 24.99
	std::cin >> book;
	// write ISBN, number of copies sold, total revenue, and average price
	//0-201-7353-x 4 99.96 24.99
	std::cout << book << std::endl;
	return 0;
}