#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"
using namespace std;

int main(){
	BinaryTree theTree;
	theTree.addNode(50, "Boss");
	theTree.addNode(25, "Vice President");
	theTree.addNode(15, "Office Manager");
	theTree.addNode(30, "Secretary");
	
	cout << "In Order Traversal (Recursive): ";
	theTree.in_orderTraverseTree(theTree.Getroot());
	cout << "\nIn Order Traversal (Non Recursive): ";
	theTree.in_orderTraverseTreeNR(theTree.Getroot());
	
	
	if(theTree.Search(15))
		cout << "\n\nElement found.\n";
	else
		cout << "\n\nElement not found.\n";
		
	Node* temp = theTree.RSearch(theTree.Getroot(),15);
	if(temp)
		cout << temp->key << " found\n";
	else
		cout << "not found.\n";
	return 0;
}
