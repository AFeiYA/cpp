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
            //usually this is a system error, not much we can do
            //For example, a write to a file that is full or a bad disk
            //How to make this error happen on purpose? 
            //std::cin.setstate(std::cin.badbit);
			throw std::runtime_error("IO stream corrupted");
		}
        if (is.fail())
        {
            // input is bad, so we need to clear the stream and reset the state
			// int ival; so if the input is not an integer, the stream will be in a bad state
            std::cerr << "bad data, try again" << std::endl;
            // clear the stream so we can continue to use it
			is.clear();
            // discard input so that we can go on
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
    // old state of the stream, so we can reset it later
    auto old_state = std::cin.rdstate();
    // clear the stream so we can use it
    std::cin.clear();
    // process the input, if there is an error, it will throw an exception
    process_input(std::cin);
    // reset the stream to its old state
    std::cin.setstate(old_state);
    std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.badbit);
    std::cout << "Hello World!\n";
	return 0;
}


