// ch02.cpp : Defines the entry point for the application.
//

#include "ch02.h"

using namespace std;

int main()
{
	//2.5
	cout<<'a'<<endl; // output: a(character literal)
	cout<<L'a'<<endl; // output: 97 (wide character literal)
	cout<<"a"<<endl; // output: a (string literal)
	cout<<L"b"<<endl; // output: 00007FF77872AC18 (wide character string literal,)
	cout<<10<<endl; // output: 10 (decimal literal)
	cout<<10u<<endl; // output: 10 (unsigned decimal literal)
	cout<<10L<<endl; // output: 10 (long decimal literal)
	cout<<10uL<<endl; // output: 10 (unsigned long decimal literal)
	cout<<012<<endl; // output: 10 (octal literal)
	cout<<0xC<<endl; // output: 12 (hexadecimal literal)
	cout << 3.14 << endl; // output: 3.14 (double literal)
	cout << 3.14f << endl; // output: 3.14 (float literal)
	cout << 3.14L << endl; // output: 3.14 (long double literal)
	cout << 10. << endl; // output: 10 (double literal)
	cout << 10e-2 << endl; // output: 0.1 (double literal)
	cout << 9<<endl; // output: 9 
	//cout << 09 <<endl; // output: error: invalid digit "9" in octal constant

	// what type does the literal have?
	auto a = "Who goes with F\145rgus?\012";
	cout << a << endl; // output: Who goes with Fergus?(string literal)
	auto b = 3.14e1L;
	cout << "long double: " << b << endl; // output: 3.14x10^1 
	auto c = 1024.f;
	auto d = 3.14L;




	return 0;
}
