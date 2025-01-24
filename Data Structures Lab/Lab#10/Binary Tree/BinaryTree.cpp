#include "BinaryTree.h"
#include <iostream>
#include <stack>
using namespace std;

Node:: Node(int key) {
	this->key = key;
	this->leftChild = NULL;
	this->rightChild= NULL;
}

// Queue's Implementation

Queue:: Queue(){
	front = rear = -1;
	size = 10;
	Q = new Node*[size];
}

Queue::	Queue(int size){
	front = rear = -1;
	this->size = size;
	Q= new Node*[this->size];
}

void Queue:: Enqueue(Node* x){
	if(rear==size-1)
		cout << "Queue is full";
	else
		Q[++rear] = x;
}

Node* Queue:: dequeue(){
	Node* x= NULL;
	if(front == rear){
		cout << "Queue is empty";
	}
	else{
		x = Q[++front];
	}
	return x;
}

void Queue:: Display(){
	for(int i=front+1; i<=rear; i++){
		cout << Q[i] << " ";
	}
	cout << endl;
}

bool Queue:: isEmpty(){
	if(front == rear)
		return true;
	return false;
}

// Binary Tree's Implementation
BinaryTree:: BinaryTree(){
	root = NULL;
}

Node* BinaryTree:: Getroot(){
	return root;
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


void BinaryTree:: CreateTree(){
	Node *p, *t;
	int x;
	Queue q(100);
	
	cout << "Enter root value : ";
	cin >> x;
	root = new Node(x);
	q.Enqueue(root);
	
	while(!q.isEmpty()){
		p=q.dequeue();
		cout << "Enter the value for lchild for " << p->key << ":\t";
		cin >> x;
		if(x!=-1){
			t = new Node(x);
			p->leftChild = t;
			q.Enqueue(t);
		}
		
		cout << "Enter the value for rchild for " << p->key << ":\t";
		cin >> x;
		if(x!=-1){
			t = new Node(x);
			p->rightChild = t;
			q.Enqueue(t);
		}
	}
}

bool BinaryTree:: RSearch(Node* p, int key)
{
    if (p == NULL)
        return false;
    if (p->key == key)
        return true;
    bool check1 = RSearch(p->leftChild, key);
    
	if(check1) 
		return true; 
    bool check2 = RSearch(p->rightChild, key);
 
    return check2;
}

bool BinaryTree:: Search(int key){
	Node* t = root;
	while(t!=NULL){
		if(key==t->key)
			return true;
		t = t->leftChild;
	}
	
	t = root;
	while(t!=NULL){
		if(key==t->key)
			return true;
		t = t->rightChild;
	}
	
	return false;
}
