
#include <iostream>
#include "ch02.h"

std::string global_str;
int global_int;

int main()
{
	// 为什么只有local_int不初始化,编译器会报错? Run-Time Check Failure #3 - The variable 'local_int' is being used without being initialized. 
	int local_int=10;
	std::string local_str;
	std::cout<< "global_str: " << global_str << std::endl;
	std::cout<< "global_int: " << global_int << std::endl;
	std::cout<< "local_int: " << local_int << std::endl;
	std::cout<< "local_str: " << local_str << std::endl;
	std::cout<< "pi: " << pi << std::endl;

	return 0;
}
