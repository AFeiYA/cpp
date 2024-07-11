#include "BST.h"
#include <iostream>
#include <queue>



void BST::Insert(int key)
{
	root = Insert(root, key);
}

Node* BST::Insert(Node* p, int key)
{
	Node* t;

	if (p == nullptr) {
		t = new Node;
		t->data = key;
		t->left = t->right = nullptr;
		return t;
	}

	if (key < p->data) {
		p->left = Insert(p->left, key);
	}
	else if (key == p->data) {
		std::cout << "Duplicate key: " << key << std::endl;
		return p;
	}
	else if (key > p->data) {
		p->right = Insert(p->right, key);
	}

	return p;
}




Node* BST::Search(int key)
{
	return Search(root, key);
}

Node* BST::Search(Node* p, int key)
{
	if (p == nullptr) {
		return nullptr;
	}

	if (key == p->data) {
		return p;
	}

	if (key < p->data) {
		return Search(p->left, key);
	}

	return Search(p->right, key);
}


Node* BST::IterativeSearch(int key)
{
	Node* t = root;

	while (t != nullptr) {
		if (key == t->data) {
			return t;
		}
		else if (key < t->data) {
			t = t->left;
		}
		else {
			t = t->right;
		}
	}

	return nullptr;
}

Node* BST::Delete(Node* p, int key)
{
	Node* q;

	if (p == nullptr) {
		return nullptr;
	}

	if (p->left == nullptr && p->right == nullptr) {
		if (p == root) {
			root = nullptr;
		}
		delete p;
		return nullptr;
	}

	if (key < p->data) {
		p->left = Delete(p->left, key);
	}
	else if (key > p->data) {
		p->right = Delete(p->right, key);
	}
	else {
		if (Height(p->left) > Height(p->right)) {
			q = InPre(p->left);
			p->data = q->data;
			p->left = Delete(p->left, q->data);
		}
		else {
			q = InSucc(p->right);
			p->data = q->data;
			p->right = Delete(p->right, q->data);
		}
	}

	return p;
}

Node* BST::InPre(Node* p)
{
	while (p && p->right != nullptr) {
		p = p->right;
	}

	return p;
}

Node* BST::InSucc(Node* p)
{
	while (p && p->left != nullptr) {
		p = p->left;
	}

	return p;
}
