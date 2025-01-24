#include "BinaryTree.h"
#include <iostream>
#include <stack>
using namespace std;

Node:: Node(int key, string name) {
	this->key = key;
	this->name = name;
	this->leftChild = NULL;
	this->rightChild= NULL;
}


// BinaryTree

BinaryTree:: BinaryTree(){
	root = NULL;
}

Node* BinaryTree:: Getroot(){
	return root;
}
void BinaryTree:: addNode(int key, string name){
	
	Node *newNode = new Node(key, name);
	if (root == NULL) {
		root = newNode;
	}
	else {
		Node *focusNode = root;
		Node *parent;
		while (true) {
			parent = focusNode;
		
			if (key < focusNode->key) {
				focusNode = focusNode->leftChild;
				if (focusNode == NULL) {
					parent->leftChild = newNode;
					return;
				}
			} 
			else{
				focusNode = focusNode->rightChild;
				if (focusNode == NULL) {
					parent->rightChild = newNode;
					return; // All Done
				}
			}
		}
	}
}

void BinaryTree:: in_orderTraverseTree (Node *focusNode){
	if(focusNode){
		in_orderTraverseTree(focusNode->leftChild);
		cout << focusNode->key << " ";
		in_orderTraverseTree(focusNode->rightChild);
	}
}
void BinaryTree:: preorderTraverseTree(Node *focusNode){
	if(focusNode){
		cout << focusNode->key << " ";
		preorderTraverseTree(focusNode->leftChild);
		preorderTraverseTree(focusNode->rightChild);
	}
}
void BinaryTree:: post_orderTraverseTree(Node *focusNode){
	if(focusNode){
		post_orderTraverseTree(focusNode->leftChild);
		post_orderTraverseTree(focusNode->rightChild);
		cout << focusNode->key << " ";
	}
}
void BinaryTree:: in_orderTraverseTreeNR(Node *focusNode){
	stack<Node*> s;
	Node *current = root;
	
	while(current!=NULL || !s.empty()){
		while(current){
			s.push(current);
			current = current->leftChild;
		}
		current = s.top();
		s.pop();
		
		cout << current->key << " ";
		current = current->rightChild;
	}
}
void BinaryTree:: preorderTraverseTreeNR(Node *focusNode){
	if (root == NULL) 
        return;
	
	stack<Node*> ss; 
    ss.push(root); 
    
    while (!ss.empty()){ 
        Node* newNode = ss.top(); 
        cout << newNode->key << " ";
        ss.pop(); 
        if (newNode->rightChild) 
            ss.push(newNode->rightChild); 
        if (newNode->leftChild) 
            ss.push(newNode->leftChild); 
    }
}
void BinaryTree:: post_orderTraverseTreeNR(Node *focusNode){
	
	if (root == NULL) 
        return;
        
    stack<Node*> ss;
    do{
    	while(root){
	    	if(root->rightChild)
	    		ss.push(root->rightChild);
	    	ss.push(root);
	    	
	    	root= root->leftChild;
		}
		
		root = ss.top();
		ss.pop();
		
		if(root->rightChild && ss.top()== root->rightChild){
			ss.pop();
			ss.push(root);
			root = root->rightChild;
		}
		else{
			cout << root->key << " ";
			root = NULL;
		}
	}while(!ss.empty());
}

Node* BinaryTree:: RSearch(Node* p, int key){
	if(p==NULL)
		return p;
	if(p->key == key)
		return p;
	if(key > p->key)
		return RSearch(p->rightChild,key);
	else
		return RSearch(p->leftChild,key);
}

bool BinaryTree:: Search(int key){
	Node* t = root;
	while(t!=NULL){
		if(key==t->key)
			return true;
		else if (key<t->key)
			t = t->leftChild;
		else
			t = t->rightChild;
	}
	return false;
}

Node* BinaryTree:: addNodeR(Node* p, int key, string name){
	Node* t= NULL;
	
	if(p==NULL){
		t = new Node(key,name);
		return t;
	}
	if(key<p->key)
		p->leftChild= addNodeR(p->leftChild, key,name);
	else if(key> p->key)
		p->rightChild= addNodeR(p->rightChild, key,name);
	return p;
}
