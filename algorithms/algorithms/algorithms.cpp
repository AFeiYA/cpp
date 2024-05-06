#include <iostream>
using namespace std;
// head recursion 
void fun1(int n)
{
	if (n > 0)
	{
		fun1(n - 1); //head recursion : recursive call is the first statement in the function
		std::cout << n << " ";
	}
}

// tail recursion : can convert to iteration easily
// the space complexity of recursion is O(n) and time complexity is O(n)
// the space complexity of iteration is O(1) and time complexity is O(n)
// so, iteration is better than recursion
void fun2(int n)
{
	if (n > 0)
	{
		std::cout << n << " ";
		fun2(n - 1); //tail recursion : recursive call is the last statement in the function
	}
}

// tree recursion
// time complexity is O(2^n) = 2^(n+1)-1 and space complexity is O(n). 
// it is not good to use tree recursion
void fun3(int n)
{
	if (n > 0)
	{
		std::cout << n << " ";
		fun3(n - 1);
		fun3(n - 1);
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
	cout<<endl;
	cout<<"Tree Recursion: ";
	fun3(3);
	// 3 2 1 1 2 1 1
	cout<<endl;
    return 0;
}
