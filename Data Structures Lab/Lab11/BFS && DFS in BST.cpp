#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
public:
	int data;
	Node* lchild;
	Node* rchild;
	
	Node(){
		data = 0;
		this->lchild = this->rchild = NULL;
	}
	Node(int data){
		this->data = data;
		this->lchild = this->rchild = NULL;
	}
};

class BinarySearchTree{
	Node* root;
public:
	BinarySearchTree(){
		root = NULL;
	}
	
	void Insert(int key){
		
		if(!root){
			Node* temp = new Node(key);
			root = temp;
			return;
		}
		
		Node* temp= root, *r;
		while(temp){
			r= temp;
			if(key < temp->data)
				temp = temp->lchild;
			else if(key > temp->data)
				temp = temp->rchild;
			else
				return;
		}
		
		Node* temp2 = new Node(key);
		if(r->data > key)
			r->lchild = temp2;
		else
			r->rchild = temp2;
		
	}
	
	bool BreathFirstSearching(int key){
		queue<Node*> q1;
		q1.push(root);
		while(!q1.empty()){
			Node* temp = q1.front();
			q1.pop();
			if(temp->data == key)
				return true;
				
			if(temp->lchild) q1.push(temp->lchild);
			if(temp->rchild) q1.push(temp->rchild);
		}
		return false;
	}
	
	bool DepthFirstSearching(int key){
		stack <Node*> s1;
		s1.push(root);
		while(!s1.empty()){
			Node* temp = s1.top();
			s1.pop();
			if(temp->data == key)
				return true;
				
			if(temp->lchild) s1.push(temp->lchild);
			if(temp->rchild) s1.push(temp->rchild);
		}
		return false;
	}
	
	void InOrder(Node *ptr){
		if(ptr){
			InOrder(ptr->lchild);
			cout << ptr->data<< " ";
			InOrder(ptr->rchild);
		}
	}
	
	Node* getRoot() const{
		return root;
	}
};

int main(){
	BinarySearchTree Tree;
	Tree.Insert(10);
	Tree.Insert(5);
	Tree.Insert(20);
	Tree.Insert(25);
	Tree.Insert(15);
	Tree.Insert(35);
	Tree.Insert(50);
	
	cout << "Inorder traversal : ";
	Tree.InOrder(Tree.getRoot());
	cout << endl << endl;
	
	cout << "Searching for key 25 in BFS: ";
	if(Tree.BreathFirstSearching(25))
		cout << "found\n";
	else cout << "Not found.\n";
		
	
	cout << "Searching for key 50 in DFS: ";
	if(Tree.DepthFirstSearching(25)) 
		cout << "found\n";
	else cout << "Not found.\n";
	
	return 0;
}
