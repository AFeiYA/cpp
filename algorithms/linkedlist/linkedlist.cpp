

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

struct Node
{
    int data;
    // Self referential structure
    Node *next;
}*first = NULL;

void create(int A[], int n)
{
	Node *t, *last;
	first = new Node;
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (int i = 1; i < n; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

void Display(Node* p)
{
	while (p != NULL)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
}
int Count(Node* p)
{
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

int Add(Node* p)
{
	int sum = 0;
	while (p != NULL)
	{
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int Max(Node* p)
{
	int max = INT_MIN;
	while (p != NULL)
	{
		if (p->data > max)
		{
			max = p->data;
		}
		p = p->next;
	}
	return max;
}
Node* LSearch(Node* p, int key)
{
	while (p != NULL)
	{
		if (key == p->data)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}
// Inserting a node in a linked list
void Insert(Node* p, int index, int x)
{
	Node* t;
	// Check if the index is valid or not 
	// If the index is less than 0 or greater than the number of nodes in the linked list, return
	if (index < 0 || index > Count(p))
	{
		return;
	}
	t = new Node;
	t->data = x;
	// If the index is 0, insert the new node at the beginning of the linked list
	if (index == 0)
	{
		// Set the link field of the new node to point to the first node in the sequence
		t->next = first;
		first = t;
	}
	else
	{
		// Traverse the linked list to find the node at the given index
		// Set the link field of the new node to point to the next node in the sequence
		for (int i = 0; i < index - 1; i++)
		{
			p = p->next;
		}
		// Set the link field of the previous node to point to the new node
		t->next = p->next;
		p->next = t;
	}
}

void SortedInsert(Node* p, int x)
{
	Node* q = NULL;
	Node* t;
	t = new Node;
	t->data = x;
	t->next = NULL;
	if (first == NULL)
	{
		first = t;
	}
	else
	{
		while (p && p->data < x)
		{
			q = p;
			p = p->next;
		}
		if (p == first)
		{
			t->next = first;
			first = t;
		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
	}
}

int Delete(Node* p, int index)
{
	Node* q = NULL;
	int x = -1;
	if (index < 1 || index > Count(p))
	{
		return -1;
	}
	if (index == 1)
	{
		q = first;
		x = first->data;
		first = first->next;
		delete q;
		return x;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
		return x;
	}
}
bool IsSorted(Node* p)
{
	int x = INT_MIN;
	while (p != NULL)
	{
		if (p->data < x)
		{
			return false;
		}
		x = p->data;
		p = p->next;
	}
	return true;
}
// Remove duplicates from a sortd linked list
void RemoveDuplicates(Node* p)
{
	Node* q = p->next;
	while (q != NULL)
	{
		if (p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			delete q;
			q = p->next;
		}
	}
}


int main()
{
    int A[] = {3, 5, 7, 10, 15};

	create(A, 5);

	Insert(first, 0, 1);

	SortedInsert(first, 9);
	SortedInsert(first, 2);
	Display(first);


	std::cout << std::endl;
	Delete(first, 1);
	Delete(first, 2);
	Insert(first,2, 5);
	Display(first);
	IsSorted(first) ? std::cout << "Sorted" : std::cout << "Not Sorted" << std::endl;
	RemoveDuplicates(first);
	Display(first);
	std::cout << std::endl;
	std::cout << "Count: " << Count(first) << std::endl;
	std::cout << "Sum: " << Add(first) << std::endl;
	std::cout << "Max: " << Max(first) << std::endl;

	return 0;
}