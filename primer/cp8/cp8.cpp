#include <iostream>
//8.1.2 : 8.1
std::istream& process_input(std::istream& is)
{
    int ival;
    // read until end-of-file, reading only integers
    while (is >> ival, !is.eof())
    {
        if (is.bad())
        {
			throw std::runtime_error("IO stream corrupted");
		}
        if (is.fail())
        {
			std::cerr << "bad data, try again" << std::endl;
			is.clear();
			is.ignore(100, '\n');
			continue;
		}
		std::cout << ival << std::endl;
	}
    // reset the stream so that it is valid for other input
    is.clear();
    return is;
}

int main()
{

    auto old_state = std::cin.rdstate();
    std::cin.clear();
    process_input(std::cin);
    std::cin.setstate(old_state);
    std::cout << "Hello World!\n";
    //复位failbit和badbit
    //std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.badbit);
	return 0;
}


