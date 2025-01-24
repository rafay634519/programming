#include <iostream>
using namespace std;

#ifndef BINARYTREE_H
#define BINARYTREE_H

class Node{
public:
	int key;
	Node* leftChild;
	Node* rightChild;
	Node(int);
};

class Queue{
private:
	int front;
	int rear;
	int size;
	Node **Q;
public:
	Queue();
	Queue(int size);
	void Enqueue(Node* x);
	Node* dequeue();
	void Display();
	bool isEmpty();
};

class BinaryTree{
private:
	Node* root;
public:
	BinaryTree();
	Node* Getroot();
	void CreateTree();
	void in_orderTraverseTree (Node*);
	void preorderTraverseTree(Node*);
	void post_orderTraverseTree (Node*);
	void in_orderTraverseTreeNR (Node*);
	void preorderTraverseTreeNR (Node*);
	void post_orderTraverseTreeNR (Node*);
	bool RSearch(Node*, int);
	bool Search(int key);
};

#endif
