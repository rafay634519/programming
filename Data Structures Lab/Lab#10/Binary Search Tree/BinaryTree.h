#include <iostream>
#include <cstring>

#ifndef BINARYTREE_H
#define BINARYTREE_H

using namespace std;

class Node {
public:
	int key;
	string name;
	Node *leftChild;
	Node *rightChild;
	Node(int,string);
};

class BinaryTree {
private:
	Node *root;
public:
	BinaryTree();
	void addNode(int, string);
	Node* addNodeR(Node*, int, string);
	void in_orderTraverseTree (Node*);
	void preorderTraverseTree(Node*);
	void post_orderTraverseTree (Node*);
	void in_orderTraverseTreeNR (Node*);
	void preorderTraverseTreeNR (Node*);
	void post_orderTraverseTreeNR (Node*);
	Node* Getroot();
	bool Search(int);
	Node* RSearch(Node*, int);
};

#endif
