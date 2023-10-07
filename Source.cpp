#include<iostream>
#include"Tree.h"
using namespace std;
void main() {
	Tree t;
	/*
	t.AddSorted(20);
	t.AddSorted(15);
	t.AddSorted(30);
	t.AddSorted(10);
	t.AddSorted(18);
	t.AddSorted(21);
	t.AddSorted(35);
	t.AddSorted(3);
	t.AddSorted(11);
	t.AddSorted(16);
	t.AddSorted(17);
	t.AddSorted(25);
	t.AddSorted(24);
	t.AddSorted(29);
	t.AddSorted(40);
	*/

	t.AddSorted(40);
	t.AddSorted(45);
	t.AddSorted(35);
	t.AddSorted(36);
	t.AddSorted(23);
	t.AddSorted(25);
	t.AddSorted(24);
	t.AddSorted(30);
	t.AddSorted(29);
	t.AddSorted(32);

	cout << "Leva suma: " << t.LeftSum() << endl;
	cout << "Desna suma: " << t.RightSum() << endl;
	cout << "Broj cvorova: " << t.NumberOfNodes() << endl;
	cout << "Broj listova: " << t.NumberOfLeaves() << endl;
	cout << "Visina: " << t.Height() << endl;
	Node* tmp = t.FindNodeWithLargestRightSubtree();
	cout << "Node with largest SubTree: " << tmp->info << endl;

	//cout << "Broj cvora levog podstabla: " << t.LeftSubTreeNodes() << endl;
	//cout << "Broj cvora desnog podstabla: " << t.RightSubTreeNodes() << endl;

	t.PreOrder();
	cout << endl;
	//t.IterativePreorder();
	//cout << endl;
	//t.IterativniInorder();
	//cout << endl;
	//t.IterativniPostOrder();
	//cout << endl;

	system("pause");
}