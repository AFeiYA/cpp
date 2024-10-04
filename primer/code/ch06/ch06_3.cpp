#include <iostream>
#include <string>
#include <array>
#include "ch06.h"

using namespace std;
//
char& get_val(string& str, string::size_type ix)
{
	return str[ix];
}
const string& shortString(const string& s1, const string& s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}
// crash because the return value is a reference to a local variable
const string& manip()
{
	string ret;
	if(!ret.empty())
		return ret;
	else
		return "Empty";
}
string make_plural(size_t ctr, const string& word, const string& ending)
{
	return (ctr > 1) ? word + ending : word;
}

int& get(int* array, int index)
{
	return array[index];
}


int main()
{
	string s("a value");
	cout << s << endl;
	get_val(s, 0) = 'A';// change the first character to 'A'
	cout << s << endl;
	
	string s1("hello"), s2("world");
	auto sz = shortString(s1, s2).size();
	cout << sz << endl;
	int odd[] = {1, 3, 5, 7, 9};
	int even[] = {0, 2, 4, 6, 8};

	auto &ref = get(odd, 1);
	cout << ref << endl;

	return 0;
}
