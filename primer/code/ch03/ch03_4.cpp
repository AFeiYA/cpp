#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	//迭代器
	string str("some string");
	for (auto it = str.begin(); it != str.end() && !isspace(*it); ++it)
		*it = toupper(*it);
	cout << str << endl;

	vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (auto it = vec.begin(); it != vec.end(); ++it)
			*it *= *it;			//平方
			
	for (auto it = vec.begin(); it != vec.end(); ++it)
		cout << *it << " ";
	cout << endl;

	auto begin = vec.begin(), end = vec.end();
	//why mid = begin + (end - begin) / 2; not mid = (begin + end) / 2;
	//because begin + end is not a valid expression
	auto mid = begin + (end - begin) / 2;
	//binary_search
	int sought = 10;
	while (mid != end && *mid != sought)
	{
	if (sought < *mid)
		end = mid;
	else
		begin = mid + 1;
	mid = begin + (end - begin) / 2;
	}
	cout << *mid << endl;

	return 0;
}
