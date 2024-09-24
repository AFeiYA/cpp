#include <iostream>
#include <string>
using namespace std;


int main()
{
	cout << "Hello CMake CH03." << endl;

	//3.6 for循环 将字符串中的字符改为X
	string s("Hello World!");
	for (auto &c : s)
		c = 'X';
	cout << s << endl;
	//3.8 while循环
	string s1("Hello World!");
	//使用decltype关键字，让index的类型和s1.size()返回的类型一样
	decltype(s1.size()) index = 0;
	cout << "s1.size() type = " << typeid(s1.size()).name() << endl;
	while (index < s1.size())
	{
		s1[index] = 'X';
		++index;
	}
	cout << s1 << endl;
	//3.9 读入一个包含标点符号的字符串,将标点符号去掉,输出剩下的字符串
	string result;	
	while(getline(cin, result))
	{
		for (auto& c : result)
		{
			if (!ispunct(c))
			{
				cout<<c;
			}
		}
		cout <<endl;
	}
	//3.11 下面的范围for循环是否合法,如果合法输出结果,如果不合法修改并输出修改后的结果
	const string s2 = "Keep out!";
	for (auto& c : s2)
	{
		cout << c << endl;
		auto c = 'X';
		// 这里的c是一个新的变量，不会改变s2的值,所以这里是合法的,因为c是一个新的变量,
		cout << c << endl;
	}
	//
	cout << s2 << endl;
	return 0;
}
