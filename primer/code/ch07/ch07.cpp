#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Screen.h"
using namespace std;

int main()
{	
	Person p1;
	Person p2("Tom");
	Person p3("Tom", "Beijing");
	cout << p1.getName() << " " << p1.getAddress() << endl;
	cout << p2.getName() << " " << p2.getAddress() << endl;
	//Person p4(cin);
	//p4.print(cout, p2);
	p3.print(cout);
	cout << endl;
	Screen myScreen(5, 5, 'X');
	auto x = myScreen.get();
	cout <<"X : " << x << endl;
	auto y = myScreen.get(0, 0);
	cout <<"Y : " << y << endl;

	return 0;
}
