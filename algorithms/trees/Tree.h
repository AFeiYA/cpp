#pragma once
// Node structure will be used in the Tree  BST and AVL Tree
// Where should I put this?
// In the Tree.h file
// Why?
// Because it is used in the Tree class
// What is the purpose of this class?
// To represent a node in a binary tree
// What is the data?
// An integer
// What are the left and right pointers?
// Pointers to the left and right children
// Can BST inherit from Node?
// No
// Why?
// Because Node is not a class
// Can BST have a Node object?
// Yes
// Why?
// Because Node is a class
// Can BST inherit from Tree?
// Yes
// How?
// By using the public keyword
class Node
{
public:
	int data;
	Node *left;
	Node *right;
};

class Tree
{
public:
	Node* root;
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

