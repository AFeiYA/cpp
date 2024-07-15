#include "AVL.h"
#include <iostream>
#include <queue>

int AVL::NodeHeight(Node* p)
{
	int hl, hr;

	hl = p && p->left ? p->left->height : 0;
	hr = p && p->right ? p->right->height : 0;

	return hl > hr ? hl + 1 : hr + 1;
}
Node* AVL::LLRotation(Node* p)
{
	Node* pl = p->left;
	Node* plr = pl->right;

	pl->right = p;
	p->left = plr;

	p->height = NodeHeight(p);
	pl->height = NodeHeight(pl);

	if (root == p) {
		root = pl;
	}

	return pl;
}
Node* AVL::RRRotation(Node* p)
{
	Node* pr = p->right;
	Node* prl = pr->left;

	pr->left = p;
	p->right = prl;

	p->height = NodeHeight(p);
	pr->height = NodeHeight(pr);

	if (root == p) {
		root = pr;
	}

	return pr;
}
Node* AVL::LRRotation(Node* p)
{
	Node* pl = p->left;
	Node* plr = pl->right;

	pl->right = plr->left;
	p->left = plr->right;

	plr->left = pl;
	plr->right = p;

	pl->height = NodeHeight(pl);
	p->height = NodeHeight(p);
	plr->height = NodeHeight(plr);

	if (root == p) {
		root = plr;
	}

	return plr;
}
Node* AVL::RLRotation(Node* p)
{
	Node* pr = p->right;
	Node* prl = pr->left;

	pr->left = prl->right;
	p->right = prl->left;

	prl->right = pr;
	prl->left = p;

	pr->height = NodeHeight(pr);
	p->height = NodeHeight(p);
	prl->height = NodeHeight(prl);

	if (root == p) {
		root = prl;
	}

	return prl;
}
int AVL::BalanceFactor(Node* p)
{
	int hl, hr;

	hl = p && p->left ? p->left->height : 0;
	hr = p && p->right ? p->right->height : 0;

	return hl - hr;
}
Node* AVL::Balance(Node* p)
{
	int bf = BalanceFactor(p);

	if (bf == 2) {
		if (BalanceFactor(p->left) == 1) {
			return LLRotation(p);
		}
		else {
			return LRRotation(p);
		}
	}
	else if (bf == -2) {
		if (BalanceFactor(p->right) == -1) {
			return RRRotation(p);
		}
		else {
			return RLRotation(p);
		}
	}

	return p;
}
Node* AVL::Insert(Node* p, int key)
{
	Node* t;

	if (p == nullptr) {
		t = new Node;
		t->data = key;
		t->height = 1;
		t->left = t->right = nullptr;
		return t;
	}

	if (key < p->data) {
		p->left = Insert(p->left, key);
	}
	else if (key > p->data) {
		p->right = Insert(p->right, key);
	}

	p->height = NodeHeight(p);

	return Balance(p);
}
Node* AVL::Delete(Node* p, int key)
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
		if (NodeHeight(p->left) > NodeHeight(p->right)) {
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

	p->height = NodeHeight(p);

	return Balance(p);
}
Node* AVL::InPre(Node* p)
{
	while (p && p->right != nullptr) {
		p = p->right;
	}

	return p;
}
Node* AVL::InSucc(Node* p)
{
	while (p && p->left != nullptr) {
		p = p->left;
	}

	return p;
}
Node* AVL::Search(int key)
{
	return Search(root, key);
}
Node* AVL::Search(Node* p, int key)
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
Node* AVL::IterativeSearch(int key)
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
Node* AVL::CreateFromPreorder(int* pre, int n)
{
	Node* p = new Node;
	int i = 0;
	std::queue<Node*> q;
	Node* t;

	p->data = pre[i++];
	p->left = p->right = nullptr;
	root = p;
	q.push(p);

	while (i < n) {
		t = nullptr;

		while (!q.empty() && pre[i] > q.front()->data) {
			t = q.front();
			q.pop();
		}

		if (t != nullptr) {
			t->right = new Node;
			t->right->data = pre[i++];
			t->right->left = t->right->right = nullptr;
			q.push(t->right);
		}
		else {
			t = q.front();
			t->left = new Node;
			t->left->data = pre[i++];
			t->left->left = t->left->right = nullptr;
			q.push(t->left);
		}
	}

	return root;
}
Node* AVL::CreateFromInorder(int* in, int n)
{
	Node* p;
	Node* t;
	std::queue<Node*> q;
	int i = 0;

	root = new Node;
	root->data = in[i++];
	root->left = root->right = nullptr;
	q.push(root);

	while (i < n) {
		if (in[i] < q.front()->data) {
			t = new Node;
			t->data = in[i++];
			t->left = t->right = nullptr;
			q.front()->left = t;
			q.push(t);
		}
		else {
			if (in[i] > q.front()->data && in[i] < (q.front()->right ? q.front()->right->data : 0)) {
				t = new Node;
				t->data = in[i++];
				t->left = t->right = nullptr;
				q.front()->right = t;
				q.push(t);
			}
			else {
				q.pop();
			}
		}
	}

	return root;
}
Node* AVL::CreateFromPostorder(int* post, int n)
{
	Node* p;
	Node* t;
	std::queue<Node*> q;
	int i = n - 1;

	root = new Node;
	root->data = post[i--];
	root->left = root->right = nullptr;
	q.push(root);

	while (i >= 0) {
		if (post[i] > q.front()->data) {
			t = new Node;
			t->data = post[i--];
			t->left = t->right = nullptr;
			q.front()->right = t;
			q.push(t);
		}
		else {
			if (post[i] < q.front()->data && post[i] > (q.front()->left ? q.front()->left->data : 0)) {
				t = new Node;
				t->data = post[i--];
				t->left = t->right = nullptr;
				q.front()->left = t;
				q.push(t);
			}
			else {
				q.pop();
			}
		}
	}

	return root;
}
Node* AVL::RotateLeft(Node* p)
{
	Node* pl = p->left;
	Node* plr = pl->right;

	pl->right = p;
	p->left = plr;

	p->height = NodeHeight(p);
	pl->height = NodeHeight(pl);

	if (root == p) {
		root = pl;
	}

	return pl;
}
Node* AVL::RotateRight(Node* p)
{
	Node* pr = p->right;
	Node* prl = pr->left;

	pr->left = p;
	p->right = prl;

	p->height = NodeHeight(p);
	pr->height = NodeHeight(pr);

	if (root == p) {
		root = pr;
	}

	return pr;
}

