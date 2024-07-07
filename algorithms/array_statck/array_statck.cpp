// array_statck.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//array stack
//What is a stack?
//A stack is a data structure that stores a collection of elements
//The stack is based on the principle of last-in-first-out (LIFO)
//The last element added to the stack is the first one to be removed
//A stack is like a stack of plates or a spring-loaded stack of coins
//The two main operations involving stacks are:
//Push: Adds an element to the stack
//Pop: Removes an element from the stack
//Other stack operations include:
//Peek or Top: Returns the top element of the stack
//IsEmpty: Returns true if the stack is empty, and false otherwise
//IsFull: Returns true if the stack is full, and false otherwise
//Stacks can be implemented using arrays or linked lists

#include <iostream>

class Stack
{
    public:
		int size;
		int top;
		int* S;

	void create(int size);
	void display();
	void push(int x);
	int pop();
	int peek(int index);
	int isEmpty();
	int isFull();
	int stackTop();

};

void Stack::create(int size)
{
	S = new int[size];
	top = -1;
}
void Stack::display()
{
	for (int i = top; i >= 0; i--)
	{
		std::cout << S[i] << " ";
	}
	std::cout << std::endl;
}
void Stack::push(int x)
{
	if (top == size - 1)
	{
		std::cout << "Stack Overflow" << std::endl;
	}
	else
	{
		top++;
		S[top] = x;
	}
}
int Stack::pop()
{
	int x = -1;
	if (top == -1)
	{
		std::cout << "Stack Underflow" <<std::endl;
	}
	else
	{
		x = S[top];
		top--;
	}
	return x;
}
int Stack::peek(int index)
{
	int x = -1;
	if (top - index + 1 < 0)
	{
		std::cout << "Invalid position" << std::endl;
	}
	else
	{
		x = S[top - index + 1];
	}
	return x;
}
int Stack::isEmpty()
{
	if (top == -1)
	{
		return 1;
	}
	return 0;
}
int Stack::isFull()
{
	return top == size - 1;
}

int main()
{
	Stack stk;
	std::cout << "Enter size of stack";
	std::cin >> stk.size;
	stk.create(stk.size);
	for (int i = 0; i < stk.size; i++)
	{
		stk.push(i*20);
	}
	stk.display();
	stk.push(100);
	stk.display();
	std::cout<<stk.peek(3);
	
}
