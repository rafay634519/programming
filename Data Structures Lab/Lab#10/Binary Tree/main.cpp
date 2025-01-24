#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"
using namespace std;

int main(){
	BinaryTree theTree;
	
	theTree.CreateTree();
	theTree.in_orderTraverseTree(theTree.Getroot());
	cout << endl;
	cout << theTree.RSearch(theTree.Getroot(),5) << endl;
	cout << theTree.Search(3) << endl;
	return 0;
}
