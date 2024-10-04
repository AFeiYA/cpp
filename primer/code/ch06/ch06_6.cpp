#include "ch06_6.h"
#include <iostream>
#include <vector>
using namespace std;
void f()
{
	cout << "f()" << endl;
}
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int, int)
{
	cout << "f(int, int)" << endl;
}
void f(double, double = 3.14)
{
	cout << "f(double, double = 3.14)" << endl;
}
void f(int, double)
{
	cout << "f(int, double)" << endl;
}
void f(int, long)
{
	cout << "f(int, long)" << endl;
}
void f(int, float)
{
	cout << "f(int, float)" << endl;
}
//6.7 
bool lengthCompare(const string& str1, const string& str2)
{
	return str1.size() > str2.size();
}
int add(int a, int b)
{
	return a + b;
}
int substract(int a, int b)
{
	return a - b;
}
int multiply(int a, int b)
{
	return a * b;
}
int divide(int a, int b)
{
	return a / b;
}


int main()
{
	f();
	f(42);
	f(42, 0);


	f(2.56, 3.14);
	f(42, 2.56);
	f(42, 42.0);
	f('a', 'b');
	bool (*pf)(const string&, const string&) = lengthCompare;
	bool b1 = pf("hello", "goodbye");
	cout << b1 << endl;
	bool b2 = lengthCompare("hello", "goodbye");
	bool b3 = (*pf)("hello", "goodbye");
	cout << b2 << " " << b3 << endl;
	//6.54 
	vector <int(*)(int, int)> vec;
	vec.push_back(add);
	vec.push_back(substract);
	vec.push_back(multiply);
	vec.push_back(divide);

	for(auto f : vec)
		cout << f(6, 2) << endl;

	return 0;
}