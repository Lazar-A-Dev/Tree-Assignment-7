#include "Tree.h"
Tree::Tree() {
	root = NULL;
	nodes = 0;
}

Tree::~Tree() {

}

void Tree::AddSorted(int p) {
	if (root == NULL) {
		Node* tmp = new Node(NULL, NULL, NULL, p);
		root = tmp;
		nodes = 1;
	}
	else {
		Node* prev = NULL;
		Node* curent = root;
		while (curent != NULL) {
			prev = curent;
			if (curent->info > p)
				curent = curent->left;
			else if (curent->info <= p)
				curent = curent->right;
		}

		if (prev->info > p) {
			prev->left = new Node(NULL, NULL, prev, p);
			nodes++;
		}
		else if (prev->info <= p) {
			prev->right = new Node(NULL, NULL, prev, p);
			nodes++;
		}
	}
}

Node* Tree::FindNodeWithLargestRightSubtree() {
	return FindNodeWithLargestRightSubtree(root);
}

Node* Tree::FindNodeWithLargestRightSubtree(Node* p) {
	if (p == NULL)
		return NULL;

	FindNodeWithLargestRightSubtree(p->left);
	FindNodeWithLargestRightSubtree(p->right);

	if (RightSubTreeNodes(p->left) > RightSubTreeNodes(p->right))
		return p->left;
	else return p->right;
}

int Tree::LeftSubTreeNodes() {
	return LeftSubTreeNodes(root);
}

int Tree::LeftSubTreeNodes(Node* p) {
	if (p->left == NULL)
		return NULL;
	return NumberOfNodes(p->left);
}

int Tree::RightSubTreeNodes() {
	return RightSubTreeNodes(root);
}

int Tree::RightSubTreeNodes(Node* p) {
	if (p == NULL || p->right == NULL)
		return NULL;
	return NumberOfNodes(p->right);
}

int Tree::Compare(int a, int b) {
	if (a >= b)
		return a;
	return b;
}

Node* Tree::FindNodeOrganised(int p) {
	Node* tmp = root;
	while (tmp != NULL) {
		if (tmp->info > p)
			tmp = tmp->left;
		else if (tmp->info < p)
			tmp = tmp->right;
		else return tmp;
	}
	return 0;
}

int Tree::LeftSum() {
	return LeftSum(root);
}

int Tree::LeftSum(Node* p) {
	if (p == NULL)
		return 0;
	if (p->left != NULL) {
		Node* tmp = p->left;
		return tmp->info + LeftSum(tmp) + RightSum(tmp);
	}
	return 0;
}

int Tree::RightSum() {
	return RightSum(root);
}

int Tree::RightSum(Node* p) {
	if (p == NULL)
		return 0;
	if (p->right != NULL) {
		Node* tmp = p->right;
		return tmp->info + LeftSum(tmp) + RightSum(tmp);
	}
	return 0;
}

int Tree::NumberOfNodes() {
	return NumberOfNodes(root);
}

int Tree::NumberOfNodes(Node* p) {
	if (p == NULL)
		return 0;
	if (p != NULL)
		return 1 + NumberOfNodes(p->left) + NumberOfNodes(p->right);
}

int Tree::Height() {
	return Height(root);
}

int Tree::Height(Node* p) {
	if (p == NULL)
		return 0;
	int left = Height(p->left);
	int right = Height(p->right);
	return 1 + Compare(left, right);
}

int Tree::NumberOfLeaves() {
	return NumberOfLeaves(root);
}

int Tree::NumberOfLeaves(Node* p) {
	if (p == NULL)
		return 0;
	else if (p->left == NULL && p->right == NULL)
		return 1;
	return NumberOfLeaves(p->left) + NumberOfLeaves(p->right);
}

void Tree::PreOrder() {
	PreOrder(root);
}

void Tree::PreOrder(Node* p) {
	if (p != NULL) {
		cout << "[" << p->info << "] ";
		PreOrder(p->left);
		PreOrder(p->right);
	}
}

void Tree::IterativePreorder() {
	Node* p = root;
	int l = 0;
	Node** stack = new Node*[nodes];
	if (p != NULL) {
		stack[l++] = p;
		while (stack[0] != 0) {
			l--;
			p = stack[l];
			stack[l] = NULL;
			cout << "[" << p->info << "] ";
			if (p->right != NULL)
				stack[l++] = p->right;
			if (p->left != NULL)
				stack[l++] = p->left;
		}
	}
}

void Tree::InOrder() {
	InOrder(root);
}

void Tree::InOrder(Node* p) {
	if (p != NULL) {
		InOrder(p->left);
		cout << "[" << p->info << "] ";
		InOrder(p->right);
	}
}

void Tree::IterativniInorder() {
	Node* p = root;
	Node** stack = new Node * [nodes];
	int l = 0;
	while (p != NULL) {
		while (p != NULL) {
			if (p->right != NULL)
				stack[l++] = p->right;
			stack[l++] = p;
			p = p->left;
		}
		l--;
		p = stack[l];
		stack[l] = NULL;
		while (stack[0] != NULL && p->right == NULL) {
			cout << "[" << p->info << "] ";
			l--;
			p = stack[l];
			stack[l] = NULL;
		}
		cout << "[" << p->info << "] ";
		if (stack[0] != 0) {
			l--;
			p = stack[l];
			stack[l] = NULL;
		}
		else
			p = NULL;
	}
}

void Tree::PostOrder() {
	PostOrder(root);
}

void Tree::PostOrder(Node* p) {
	if (p != NULL) {
		PostOrder(p->left);
		PostOrder(p->right);
		cout << "[" << p->info << "] ";
	}
}

void Tree::IterativniPostOrder() {
	Node* p = root;
	Node* last = root;
	int l = 0;
	Node** stack = new Node * [nodes];
	while (p != NULL) {
		while (p->left != NULL) {
			stack[l++] = p;
			p = p->left;
		}
		while (p != NULL && (p->right == NULL || p->right == last)) {
			cout << "[" << p->info << "] ";
			last = p;
			if (stack[0] == NULL)
				return;
			l--;
			p = stack[l];
			stack[l] = NULL;
		}
		stack[l++] = p;
		p = p->right;
	}
}


