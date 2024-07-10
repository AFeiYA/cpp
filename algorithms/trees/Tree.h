#pragma once

class Node
{
public:
	int data;
	Node *left;
	Node *right;
};

class Tree
{
	Node *root;
public:
	Tree() { root = nullptr; }
	void CreateTree();
	void Preorder(Node *p);
	void Preorder() { Preorder(root); }
	void Inorder(Node *p);
	void Inorder() { Inorder(root); }
	void Postorder(Node *p);
	void Postorder() { Postorder(root); }
	void Levelorder(Node *p);
	void Levelorder() { Levelorder(root); }
	int Height(Node *root);
	int Height() { return Height(root); }
	int Count(Node *root);
	int Count() { return Count(root); }
	int CountLeaf(Node *root);
	int CountLeaf() { return CountLeaf(root); }
	int CountNonLeaf(Node *root);
	int CountNonLeaf() { return CountNonLeaf(root); }
	int CountDegree2(Node *root);
	int CountDegree2() { return CountDegree2(root); }
	int CountDegree1(Node *root);
	int CountDegree1() { return CountDegree1(root); }
};

