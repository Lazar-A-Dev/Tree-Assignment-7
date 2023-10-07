#pragma once
#include<iostream>
using namespace std;
class Node {
public:

	Node* left, * right, * parent;
	int info;

public:

	Node() {
		left = right = parent = NULL;
		info = 0;
	}

	Node(Node* left, Node* right, Node* parent, int info) {
		this->left = left;
		this->right = right;
		this->parent = parent;
		this->info = info;
	}

	~Node() {}
};
