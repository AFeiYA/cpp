#include <iostream>
#include <string>
#include "ch06.h"

using namespace std;
//6.3
int fact(int val)
{
	int ret = 1;
	while(val > 1)
		ret *= val--;
	return ret;
}
//6.4
int fact()
{
	int val;
	int ret = 1;
	cout << "Please enter a number: ";
	cin >> val;
	while(val > 1)
		ret *= val--;
	return ret;
}
//6.5
void absolute(int val)
{
	cout << "The absolute value of " << val << " is " << (val > 0 ? val : -val) << endl;
}
//6.6 local static variable
size_t count_calls()
{
	static size_t ctr = 0;
	return ctr++;
}
//6.10
void swap(int& v1, int& v2)
{
	int temp = v1;
	v1 = v2;
	v2 = temp;
}
// what is string::size_type?
// string::size_type is a type that can represent the size of any string.
string::size_type find_char(const string& s, char c, string::size_type& occurs)
{
	auto ret = s.size();
	occurs = 0;
	for (decltype(ret) i = 0; i != s.size(); ++i)
	{
		if (s[i] == c)
		{
			if(ret == s.size())
				ret = i;
			++occurs;
		}
	}
	return ret;
}

int main(int argc, char *argv[])
{	
	if (argc >=3)
		cout << argv[1] << " " << argv[2] << endl;
	auto j = fact(5);
	cout << "5! is " << j << endl;
	//cout << fact() << endl;
	absolute(-5);
	for (size_t i = 0; i != 10; ++i)
		cout << count_calls() << " ";
	cout << endl;
	int i = 42, k = 99;
	swap(i, k);
	cout << i << " " << k << endl;

	string s = "Hello World!";
	string::size_type ctr;
	auto index = find_char(s, 'o', ctr);
	cout << "The character 'o' appears " << ctr << " times." << endl;
	return 0;
}
