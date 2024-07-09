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
};

