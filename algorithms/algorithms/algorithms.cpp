#include <iostream>
using namespace std;
// head recursion
void fun1(int n)
{
	if (n > 0)
	{
		fun1(n - 1);
		std::cout << n << " ";
	}
}

// tail recursion
void fun2(int n)
{
	if (n > 0)
	{
		std::cout << n << " ";
		fun2(n - 1);
	}
}
int main()
{
    cout<<"Head Recursion: ";
	fun1(3);	
	cout<<endl;
	// 1 2 3
	cout<<"Tail Recursion: ";
	fun2(3);
	// 3 2 1
    return 0;
}
