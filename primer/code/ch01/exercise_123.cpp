//1.23 编写程序, 读取多个销售记录, 统计每个ISBN(每本书)有几条销售记录
//1.6
#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item total;
	if (std::cin >> total) {
		Sales_item cur;
		while (std::cin >> cur) {
			if (total.isbn() == cur.isbn()) {
				total+=cur;
			}
			else {
				//print the previous record
				std::cout << total << std::endl;
				//update the total and cnt
				total = cur;
			}
		}
		//print the last record
		std::cout << total << std::endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
