// doublylinkedlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <class T>
class Node
{
public:
	T data;
	Node* prev;
	Node* next;
};

template <class T>
class DoublyLinkedList
{
	private:
		Node<T>* first;
	public:
		DoublyLinkedList() { first = NULL; }
		DoublyLinkedList(T A[], int n);
		~DoublyLinkedList();
		void Display();
		void Insert(int index, T x);
		T Delete(int index);
		int Length();
		void Reverse();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(T A[], int n)
{
	Node<T>* t, * last;
	int i = 0;

	first = new Node<T>;
	first->data = A[0];
	first->prev = first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = new Node<T>;
		t->data = A[i];
		t->next = last->next;
		t->prev = last;
		last->next = t;
		last = t;
	}
}	

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	Node<T>* p = first;
	while (first)
	{
		first = first->next;
		delete p;
		p = first;
	}
}

template <class T>
void DoublyLinkedList<T>::Display()
{
	Node<T>* p = first;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

template <class T>
void DoublyLinkedList<T>::Insert(int index, T x)
{
	Node<T>* t, * p = first;

	if (index < 0 || index > Length())
		return;

	t = new Node<T>;
	t->data = x;
	t->next = t->prev = NULL;

	if (index == 0)
	{
		t->next = first;
		first->prev = t;
		first = t;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
			p = p->next;
		t->next = p->next;
		t->prev = p;
		if (p->next)
			p->next->prev = t;
		p->next = t;
	}
}	

template <class T>
T DoublyLinkedList<T>::Delete(int index)
{
	Node<T>* p = first;
	T x = -1;

	if (index < 1 || index > Length())
		return -1;
	if (index == 1)
	{
		first = first->next;
		if (first)
			first->prev = NULL;
		x = p->data;
		delete p;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
			p = p->next;
		p->prev->next = p->next;
		if (p->next)
			p->next->prev = p->prev;
		x = p->data;
		delete p;
	}
	return x;
}

template <class T>
int DoublyLinkedList<T>::Length()
{
	Node<T>* p = first;
	int len = 0;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}

// reverse a doubly linked list
template <class T>
void DoublyLinkedList<T>::Reverse()
{
	Node<T>* p = first;
	Node<T>* temp;

	while (p)
	{
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;
		if (p && p->next == NULL)
			first = p;
	}
}	


int main()
{
	int A[] = { 10, 20, 30, 40, 50 };
	DoublyLinkedList<int> dll(A, 5);

	dll.Insert(0, 5);
	dll.Insert(3, 35);
	dll.Insert(7, 70);
	dll.Display();
	std::cout << dll.Delete(1) << std::endl;
	dll.Display();	
	dll.Reverse();
	dll.Display();

	return 0;		
}
