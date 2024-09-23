
#include <iostream>
using namespace std;

int main()
{
	int ival = 1024;
	int *pi = &ival;// pi points to an int
	int **ppi = &pi;// ppi points to a pointer to an int

	cout << "The value of ival\n"
		<< "direct value: " << ival << "\n"
		<< "indirect value: " << *pi << "\n"
		<< "address of ival: " << &ival << "\n"
		<< "doubly indirect value: " << **ppi << "\n"
		<< "address of pi: " << &pi << "\n"
		<< endl;
	return 0;
}
