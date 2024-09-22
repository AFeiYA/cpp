//1.21 编写程序, 读取两个ISBN相同的sales item, 输出他们的和

#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item book1, book2;
	//book1: 0-201-78345-x 3 20.00
	//book2: 0-201-78345-x 2 25.00
	std::cin >> book1 >> book2;
	if (book1.isbn() == book2.isbn()) {
		std::cout << book1 + book2 << std::endl;
		return 0;
	}
	else {
		std::cerr << "Data must refer to same ISBN" << std::endl;
		return -1;
	}
}