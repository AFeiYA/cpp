//1.22 编写程序, 读取多个ISBN相同的sales item销售记录, 输出他们的和
#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item total;
	if (std::cin >> total) {
		Sales_item cur;
		while (std::cin >> cur) {
			if (total.isbn() == cur.isbn()) {
				total += cur;
			}
			else {
				std::cout << total << std::endl;
				total = cur;
			}
		}

	}else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	std::cout << total << std::endl;
	return 0;
}
