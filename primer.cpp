// primer: 7.1 Defining Abstract Data Types

#include <string>
#include <iostream>
#include "Sales_data.h"


int main()
{
    Sales_data data, *p;
    std::cout << "sizeof(Sales_data) = " << sizeof(Sales_data) << std::endl;
    std::cout << "sizeof data = " << sizeof data << std::endl;
    std::cout << "sizeof p = " << sizeof p << std::endl;
    std::cout << "sizeof *p = " << sizeof *p << std::endl;
    std::cout << "sizeof data.revenue = " << sizeof data.revenue << std::endl;
    std::cout << "sizeof Sales_data::revenue = " << sizeof Sales_data::revenue << std::endl;
    return 0;
}