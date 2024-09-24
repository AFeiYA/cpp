#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	vector<int> v1;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
	}
	for (auto& i : v1)
	{
		i *= i;
	}
	for (auto i : v1)
	{
		cout << i << " ";
	}
	cout << endl;
	vector<string> v2;
	string s;
	for (auto i = 0; i <10 ; i++)
	{
		v2.push_back(to_string(i));
	}
	for (auto& i : v2)
	{
		cout << i << " ";
	}
	cout << endl;
	//3.17 读入一组词,将其转换为大写输出
	vector<string> v3;
	string s1;
	while (cin >> s1)
	{
		v3.push_back(s1);
	}
	for (auto& i : v3)
	{
		for (auto& c : i)
		{
			c = toupper(c);
		}
	}
	for (auto i : v3)
	{
		cout << i << " ";
	}
	cout << endl;
	//3.20 读入一组整数,将每对相邻整数的和输出
	cout << "Please enter some integers:" << endl;
	//clear the cin buffer
	cin.clear();
	vector<int> v4;
	int i;
	while (cin >> i)
	{
		v4.push_back(i);
	}
	for (auto i = 0; i < v4.size()-1; i += 1)
	{
		cout << v4[i] + v4[i + 1] << " ";
	}
	cout << endl;
	//输出第一个和最后一个元素的和,第二个和倒数第二个元素的和,以此类推
	for (auto i = 0; i < v4.size() / 2; i++)
	{
		cout << v4[i] + v4[v4.size() - i - 1] << " ";
	}
	cout << endl;

	return 0;
}
