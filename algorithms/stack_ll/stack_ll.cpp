// stack_ll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <class T>
class Node
{
    public:
        T data;
        Node* next;
};

template <class T>
class Stack
{
public:
	Node<T>* top;
    Stack() { top = NULL; }
	void push(T x);
	T pop();
	void Display();
	int isEmpty();
};


template <class T>
void Stack<T>::push(T x)
{
	Node<T>* t = new Node<T>;
	if (t == NULL)
	{
		std::cout << "Stack is full" << std::endl;
	}
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

template <class T>
T Stack<T>::pop()
{

	if (top == NULL)
	{
		std::cout << "Stack is empty" << std::endl;
		return -1;
	}
	else
	{
		Node<T>* t = top;
		T x = t->data;
		top = top->next;
		delete t;
		return x;
	}
}
template <class T>
void Stack<T>::Display()
{
	Node<T>* p = top;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

template <class T>
int Stack<T>::isEmpty()
{
	return top == NULL;
}


int isOperand(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
	{
		return 0;
	}
	return 1;
}

int Precedence(char c)
{
	if (c == '+' || c == '-')
	{
		return 1;
	}
	else if (c == '*' || c == '/')
	{
		return 2;
	}
	else if (c == '^')
	{
		return 3;
	}
	return 0;
}
std::string InfixToPostfix(std::string infix) {
	Stack<char> stk;
	std::string postfix;
	for (size_t i = 0; i < infix.length(); i++) {
		if (isOperand(infix[i])) {
			postfix += infix[i];
		}
		else {
			while (!stk.isEmpty() && Precedence(stk.top->data) >= Precedence(infix[i])) {
				postfix += stk.pop();
			}
			stk.push(infix[i]);
		}
	}
	while (!stk.isEmpty()) {
		postfix += stk.pop();
	}
	return postfix;
}


int main()
{
	std::string infix= "a+b*c-d/e+3^2";
	std::cout << InfixToPostfix(infix);
	return 0;
}


