#pragma once
#include<iostream>
#include"Node.h"
using namespace std;
class Tree
{
public:

	Node* root;
	int nodes;

public:

	Tree();
	~Tree();
	void AddSorted(int p);
	int LeftSum();
	int LeftSum(Node* p);
	int RightSum();
	int RightSum(Node* p);
	int LeftSubTreeNodes();
	int LeftSubTreeNodes(Node* p);
	int RightSubTreeNodes();
	int RightSubTreeNodes(Node* p);
	int NumberOfNodes();
	int NumberOfNodes(Node* p);
	int Height();
	int Height(Node* p);
	int NumberOfLeaves();
	int NumberOfLeaves(Node* p);
	Node* FindNodeOrganised(int p);
	Node* FindNodeWithLargestRightSubtree();
	Node* FindNodeWithLargestRightSubtree(Node* p);
	int Compare(int a, int b);

	void PreOrder();
	void PreOrder(Node* p);
	void IterativePreorder();
	void InOrder();
	void InOrder(Node* p);
	void IterativniInorder();
	void PostOrder();
	void PostOrder(Node* p);
	void IterativniPostOrder();
};


