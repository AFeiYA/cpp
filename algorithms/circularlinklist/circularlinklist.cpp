// circularlinklist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Circular Linked List
// What is a circular linked list?
// A circular linked list is a linked list in which the last node points to the first node, forming a circle
// Circular linked lists can be singly circular or doubly circular
// singly circular
// In a singly circular linked list, each node has a link field that points to the next node in the sequence, and the last node points to the first node
// How to implement a circular linked list?
// To implement a circular linked list, we need to create a node structure with a data field and a link field
// We also need to create a circular linked list class with methods to insert, delete, and display nodes
// We can create a circular linked list from an array by iterating through the array and creating nodes for each element
// We can display a circular linked list by iterating through the nodes and printing the data field

template <class T>
class Node
{
public:
	T data;
	Node* next;
};

template <class T>
class CircularLinkedList
{
private:
	Node<T>* head;
	public:
		CircularLinkedList() { head = NULL; }
		CircularLinkedList(T A[], int n);
		~CircularLinkedList();
		void Display();
		void Insert(int index, T x);
		T Delete(int index);
		int Length();
};

// Creating a circular linked list from an array
template <class T>
CircularLinkedList<T>::CircularLinkedList(T A[], int n)
{
	Node<T>* t, * last;
	int i = 0;

	head = new Node<T>;
	head->data = A[0];
	head->next = head;
	last = head;

	for (i = 1; i < n; i++)
	{
		t = new Node<T>;
		t->data = A[i];
		t->next = last->next;
		last->next = t;
		last = t;
	}
}
// Destructor for circular linked list
template <class T>
CircularLinkedList<T>::~CircularLinkedList()
{
	Node<T>* p = head;
	while (p->next != head)
	{
		p = p->next;
	}
	if (p == head)
	{
		delete head;
		head = NULL;
	}
	else
	{
		p->next = head->next;
		delete head;
		head = p->next;
	}
}

// Displaying a circular linked list
template <class T>
void CircularLinkedList<T>::Display()
{
	Node<T>* p = head;
	do
	{
		std::cout << p->data << " ";
		p = p->next;
	} while (p != head);
	std::cout << std::endl;
}

// Inserting a node in a circular linked list
template <class T>
void CircularLinkedList<T>::Insert(int index, T x)
{
	Node<T>* t, * p = head;

	if (index < 0 || index > Length())
		return;

	t = new Node<T>;
	t->data = x;
	t->next = NULL;

	if (index == 0)
	{
		if (head == NULL)
		{
			head = t;
			head->next = head;
		}
		else
		{
			while (p->next != head)
				p = p->next;
			p->next = t;
			t->next = head;
			head = t;
		}
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
	}
}
// Deleting a node from a circular linked list
template <class T>
T CircularLinkedList<T>::Delete(int index)
{
	Node<T>* p = head, * q = NULL;
	T x;
	int i;

	if (index < 0 || index > Length())
		return -1;

	if (index == 1)
	{
		while (p->next != head)
			p = p->next;
		x = head->data;
		if (head == p)
		{
			delete head;
			head = NULL;
		}
		else
		{
			p->next = head->next;
			delete head;
			head = p->next;
		}
	}
	else
	{
		for (i = 0; i < index - 2; i++)
			p = p->next;
		q = p->next;
		p->next = q->next;
		x = q->data;
		delete q;
	}
	return x;
}

// Finding the length of a circular linked list
template <class T>
int CircularLinkedList<T>::Length()
{
	Node<T>* p = head;
	int len = 0;

	do
	{
		len++;
		p = p->next;
	} while (p != head);
	return len;
}


#include <iostream>

int main()
{
    int A[] = { 2, 3, 4, 5, 6 };
	CircularLinkedList<int> cl(A, 5);
	cl.Display();
	cl.Insert(0, 10);
	cl.Display();
	cl.Insert(3, 20);
	cl.Display();
	cl.Delete(1);
	cl.Display();
	cl.Delete(3);
	cl.Display();
	cl.Delete(0);
	cl.Display();
	std::cout<< cl.Length() <<std::endl;
	std::string B[] = { "apple", "banana", "cherry", "date", "elderberry" };
	CircularLinkedList<std::string> cl2(B, 5);
	cl2.Display();
	cl2.Insert(0, "fig");
	cl2.Display();
	cl2.Insert(3, "grape");
	cl2.Display();
	return 0;
}