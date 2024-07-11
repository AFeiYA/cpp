#pragma once
#include "Tree.h"


class BST : public Tree
{
public:
	Node* Search(int key);
	Node* Search(Node* p, int key);
	Node* IterativeSearch(int key);
	void Insert(int key);
	Node* Insert(Node* p, int key);
	Node* Delete(Node* p, int key);
	Node* InPre(Node* p);
	Node* InSucc(Node* p);
};


