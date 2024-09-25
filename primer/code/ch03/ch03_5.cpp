#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;


int main()
{
	//3.5.3
	string nums[] = {"one", "two", "three"};
	string *p = &nums[0];
	string *p2 = nums; // equivalent to p2 = &nums[0]
	int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto ia2(ia); // ia2 is int*
	decltype(ia) ia3 = {0,1,2,3,4,5,6,7,8,9}; // ia3 is an array of ten ints)
	ia3[4] = 5;
	vector<int> ivec(begin(ia), end(ia)); // ivec contains elements from ia
	vector<int> subVec(ia+1, ia+4); // subVec contains ia[1] to ia[3]

	for (auto i:ivec)
		cout << i << " ";
	cout << endl;

	int ia22[3][4] = { // three elements; each is an array of size 4
			{0, 1, 2, 3}, // initializers for the row indexed by 0
			{4, 5, 6, 7}, // initializers for the row indexed by 1
			{8, 9, 10, 11} // initializers for the row indexed by 2
		};
	cout<< ia22[2][3] <<endl;

	size_t cnt = 0;
	for (auto& row : ia22)
	{
		for (auto& col : row)
		{
			col = cnt;
			++cnt;
			cout << col << " ";
		}
	}
	cout<<endl;
	return 0;
}
