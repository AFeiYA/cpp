
#include <iostream>
#include "ch02.h"
using namespace std;

int main()
{
	const int bufSize = 512;// 任何试图改变bufSize的操作都是非法的
	//bufSize = 512;// error: assignment of read-only variable 'bufSize'
	const double &rpi = pi;// pi的值不能改变
	cout<< &pi <<endl;
	cout<< rpi << endl;
	const double pi = 3.14;
	cout<< pi << endl;
	cout<< &pi << endl;
	//const double pi = 3.14159;// error: redefinition of 'const double pi'

	return 0;
}
