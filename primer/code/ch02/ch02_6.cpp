
#include <iostream>
#include <string>
#include "ch02_6.h"
using namespace std;

int main()
{
	Sales_data data1, data2;
	cin >> data1.bookNo >> data1.units_sold >> data1.revenue;
	data1.revenue = data1.units_sold * data1.revenue;
	cin >> data2.bookNo >> data2.units_sold >> data2.revenue;
	data2.revenue = data2.units_sold * data2.revenue;
	if (data1.bookNo == data2.bookNo)
	{
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
		if (totalCnt != 0)
			cout << totalRevenue / totalCnt << endl;
		else
			cout << "(no sales)" << endl;
		return 0;
	}
	else
	{
		cerr << "Data must refer to the same ISBN" << endl;
		return -1;
	}

	return 0;
}
