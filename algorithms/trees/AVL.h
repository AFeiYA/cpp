#pragma once
#include "BST.h"

class AVL : public BST
{
	public:
	Node* LLRotation(Node* p);
	Node* LRRotation(Node* p);
	Node* RRRotation(Node* p);
	Node* RLRotation(Node* p);
	int NodeHeight(Node* p);
	int BalanceFactor(Node* p);
	Node* Insert(Node* p, int key);
	Node* Delete(Node* p, int key);
	Node* InPre(Node* p);
	Node* InSucc(Node* p);
	Node* Search(int key);
	Node* Search(Node* p, int key);
	Node* IterativeSearch(int key);
	Node* CreateFromPreorder(int* pre, int n);
	Node* CreateFromInorder(int* in, int n);
	Node* CreateFromPostorder(int* post, int n);
	Node* Balance(Node* p);
	Node* RotateLeft(Node* p);
	Node* RotateRight(Node* p);
	int Height() { return NodeHeight(root); }

};