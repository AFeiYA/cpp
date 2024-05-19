

#include <iostream>
// Linked List
// What is a linked list?
// A linked list is a data structure that consists of a group of nodes that represent a sequence
// The nodes are connected to each other using pointers
// Each node consists of two fields: a data field and a link field
// The data field stores the data, and the link field stores the address of the next node in the sequence
// The last node in the sequence has a link field that points to NULL
// Linked lists can be singly linked, doubly linked, or circular linked
// In a singly linked list, each node has a link field that points to the next node in the sequence
// In a doubly linked list, each node has two link fields: one that points to the next node and one that points to the previous node
// In a circular linked list, the last node points to the first node, forming a circle
// Linked lists are dynamic data structures that can grow or shrink in size during execution
// Linked lists are used to implement other data structures such as stacks, queues, and graphs
// Linked lists are used to represent polynomials, sparse matrices, and other data structures
// Linked lists are used in memory management, garbage collection, and other applications
// Linked lists have several advantages over arrays, such as dynamic size, ease of insertion and deletion, and efficient memory utilization
template <class T>
class Node
{
public:
	T data;
	Node* next;
};


template <class T>
class LinkedList
{
private:
	Node<T> *first;
public:
	LinkedList() { first = NULL; }
	LinkedList(T A[], int n);
	~LinkedList();
	void Display();
	void Insert(int index, T x);
	int Delete(int index);
	int Length();
};

// Creating a linked list from an array
template <class T>
LinkedList<T>::LinkedList(T A[], int n)
{
	Node<T> *last, *t;
	int i = 0;

	first = new Node<T>;
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = new Node<T>;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}	

// Destructor for linked list
template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T> *p = first;
	while (first)
	{
		first = first->next;
		delete p;
		p = first;
	}
}

// Displaying a linked list
template <class T>
void LinkedList<T>::Display()
{
	Node<T> *p = first;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}
// Inserting a node at a given index in a linked list
template <class T>
void LinkedList<T>::Insert(int index, T x)
{
	Node<T> *t, *p = first;

	if (index < 0 || index > Length())
		return;

	t = new Node<T>;
	t->data = x;
	t->next = NULL;

	if (index == 0)
	{
		t->next = first;
		first = t;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
	}
}

// Deleting a node at a given index in a linked list
template <class T>
int LinkedList<T>::Delete(int index)
{
	Node<T> *p, *q = NULL;
	T x = -1;

	if (index < 1 || index > Length())
		return -1;
	if (index == 1)
	{
		p = first;
		first = first->next;
		x = p->data;
		delete p;
	}
	else
	{
		p = first;
		for (int i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
	}
	return x;
}

// Finding the length of a linked list
template <class T>
int LinkedList<T>::Length()
{
	Node<T> *p = first;
	int len = 0;

	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}


int main()
{
    int A[] = {3, 5, 7, 10, 15};
	int B[] = {0,2,4,6,8};

	LinkedList<int> l1(A, 5);
	std::cout<<"Length: "<<l1.Length()<<std::endl;
	l1.Display();
	l1.Insert(0, 2);
	l1.Display();
	LinkedList<int> l2(B, 5);
	l2.Display();
	return 0;
}
