#include <iostream>
#include <queue>
#include "Tree.h"

void Tree::CreateTree()
{
	Node *p, *t;
	int x;
	std::queue<Node*> q;
	root = new Node;
	std::cout << "Enter root value: ";
	std::cin >> x;
	root->data = x;
	root->left = root->right = nullptr;
	q.push(root);

	while (!q.empty()) {
		p = q.front();
		q.pop();
		std::cout << "Enter left child of " << p->data << ": ";
		std::cin >> x;
		if (x != -1) {
			t = new Node;
			t->data = x;
			t->left = t->right = nullptr;
			p->left = t;
			q.push(t);
		}
		std::cout << "Enter right child of " << p->data << ": ";
		std::cin >> x;
		if (x != -1) {
			t = new Node;
			t->data = x;
			t->left = t->right = nullptr;
			p->right = t;
			q.push(t);
		}
	}
}

void Tree::CreateTree(int value)
{
	root = new Node;
	root->data = value;
	root->left = root->right = nullptr;
}

void Tree::Preorder(Node* p)
{
	if (p) {
		std::cout << p->data << ", " << std::flush;
		Preorder(p->left);
		Preorder(p->right);
	}
}

void Tree::Inorder(Node* p)
{
	if (p) {
		Inorder(p->left);
		std::cout << p->data << ", " << std::flush;
		Inorder(p->right);
	}
}

void Tree::Postorder(Node* p)
{
	if (p) {
		Postorder(p->left);
		Postorder(p->right);
		std::cout << p->data << ", " << std::flush;
	}
}

void Tree::Levelorder(Node* p)
{
	std::queue<Node*> q;
	std::cout << root->data << ", " << std::flush;
	q.push(root);

	while (!q.empty()) {
		p = q.front();
		q.pop();
		if (p->left) {
			std::cout << p->left->data << ", " << std::flush;
			q.push(p->left);
		}
		if (p->right) {
			std::cout << p->right->data << ", " << std::flush;
			q.push(p->right);
		}
	}
}

int Tree::Height(Node* root)
{
	int x = 0, y = 0;
	if (root == nullptr) {
		return 0;
	}
	x = Height(root->left);
	y = Height(root->right);
	if (x > y) {
		return x + 1;
	}
	else {
		return y + 1;
	}
}

int Tree::Count(Node* root)
{
	int x = 0, y = 0;
	if (root == nullptr) {
		return 0;
	}
	x = Count(root->left);
	y = Count(root->right);
	return x + y + 1;
}

int Tree::CountLeaf(Node* root)
{
	int x = 0, y = 0;
	if (root == nullptr) {
		return 0;
	}
	x = CountLeaf(root->left);
	y = CountLeaf(root->right);
	if (root->left == nullptr && root->right == nullptr) {
		return x + y + 1;
	}
	return x + y;
}

int Tree::CountNonLeaf(Node* root)
{
	int x = 0, y = 0;
	if (root == nullptr) {
		return 0;
	}
	x = CountNonLeaf(root->left);
	y = CountNonLeaf(root->right);
	if (root->left != nullptr || root->right != nullptr) {
		return x + y + 1;
	}
	return x + y;
}

int Tree::CountDegree2(Node* root)
{
	int x = 0, y = 0;
	if (root == nullptr) {
		return 0;
	}
	x = CountDegree2(root->left);
	y = CountDegree2(root->right);
	if (root->left != nullptr && root->right != nullptr) {

		return x + y + 1;
	}
	return x + y;
}
int Tree::CountDegree1(Node* root)
{
	int x = 0, y = 0;
	if (root == nullptr) {
		return 0;
	}
	x = CountDegree1(root->left);
	y = CountDegree1(root->right);
	if ((root->left != nullptr && root->right == nullptr) || (root->left == nullptr && root->right != nullptr)) {
		return x + y + 1;
	}
	return x + y;
}