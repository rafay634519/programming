#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* lchild;
	Node* rchild;
	int height;
	
	Node(int data, int height){
		this->data = data;
		this->height = height;
		this->lchild = this->rchild = NULL;
	}
};

class BST{
private:
	Node* root;
	
	void MakeEmpty(Node* ptr){
		if(!ptr) return;
		
		MakeEmpty(ptr->lchild);
		MakeEmpty(ptr->rchild);
		delete ptr;
	}
	
	Node* Insert(int key, Node* ptr){
		if(!ptr){
			ptr = new Node(key,0);
		}
		else if(ptr->data > key){
			ptr->lchild= Insert(key, ptr->lchild);
			if(height(ptr->lchild)- height(ptr->rchild)==2){
				if(key < ptr->lchild->data)
					ptr= singleRightRotate(ptr);
				else 
					ptr = doubleRightRotate(ptr);
			}
		}
		else if(ptr->data < key){
			ptr->rchild = Insert(key, ptr->rchild);
			if(height(ptr->rchild)- height(ptr->lchild)==2){
				if(key > ptr->rchild->data)
					ptr= singleLeftRotate(ptr);
				else 
					ptr = doubleLeftRotate(ptr);
			}
		}
		
		ptr->height = max(height(ptr->lchild), height(ptr->rchild))+1;
		return ptr;
	}
	
	Node* singleRightRotate(Node *ptr){
		Node* temp = ptr->lchild;
		ptr->lchild = temp->rchild;
		temp->rchild = ptr;
		ptr->height = max(height(ptr->lchild),height(ptr->rchild))+1;
		temp->height = max(height(ptr->rchild),ptr->height)+1;
		return temp;
	}
	
	Node* singleLeftRotate(Node *ptr){
		Node* temp = ptr->rchild;
		ptr->rchild = temp->lchild;
		temp->lchild = ptr;
		ptr->height = max(height(ptr->lchild),height(ptr->rchild))+1;
		temp->height = max(height(ptr->lchild),ptr->height)+1;
		return temp;
	}
	
	Node* doubleLeftRotate(Node *ptr){
		ptr->rchild = singleRightRotate(ptr->rchild);
		return singleLeftRotate(ptr);
	}
	
	Node* doubleRightRotate(Node *ptr){
		ptr->lchild = singleLeftRotate(ptr->lchild);
		return singleRightRotate(ptr);
	}
	
	Node* findMin(Node *ptr){
		if(!ptr)
			return NULL;
		else if(ptr->lchild == NULL)
			return ptr;
		else
			return findMin(ptr->lchild);
	}
	
	Node* findMax(Node *ptr){
		if(!ptr)
			return NULL;
		else if(ptr->rchild == NULL)
			return ptr;
		else
			return findMax(ptr->rchild);
	}
	
	Node* remove(int key, Node* ptr){
		Node* temp ;
		if(!ptr)
			return NULL;
		else if(key < ptr->data)
			ptr->lchild = remove(key, ptr->lchild);
		else if(key > ptr->data)
			ptr->rchild = remove (key, ptr->rchild);
			
		else if(ptr->lchild && ptr->rchild){
			temp = findMin(ptr->rchild);
			ptr->data = temp->data;
			ptr->rchild = remove(ptr->data, ptr->rchild);
		}
		else{
			temp = ptr;
			if(!ptr->lchild)
				ptr = ptr->rchild;
			else if(!ptr->rchild)
				ptr = ptr->lchild;
			delete temp;
		}
		if(!ptr)
			return ptr;
		
		ptr->height = max(height(ptr->lchild), height(ptr->rchild))+1;
		
		if((height(ptr->lchild) - height(ptr->rchild))==2){
			if(height(ptr->lchild->lchild - height(ptr->lchild->rchild))==1)
				return singleLeftRotate(ptr);
			else
				return doubleLeftRotate(ptr);
		}
		
		else if(height(ptr->rchild) - height(ptr->lchild) == 2){
			if(height(ptr->rchild->rchild) - height(ptr->rchild->lchild)==1)
				return singleRightRotate(ptr);
			else
				return doubleRightRotate(ptr);
		}
		return ptr;
	}
	
	int height(Node* ptr){
		if(!ptr)
			return 0;
		else
			return height(ptr->lchild) - height(ptr->rchild);
	}
	
	void InOrder(Node *ptr){
		if(ptr){
			InOrder(ptr->lchild);
			cout << ptr->data << " ";
			InOrder(ptr->rchild);
		}
	}
	
public:	
	BST(){
		root = NULL;
	}
	void insert(int x){
		root = Insert(x,root);
	}
	void remove(int key){
		root = remove(key, root);
	}
	void display(){
		InOrder(root);
		cout << endl;
	}
};

int main(){
	BST Tree;
	Tree.insert(67);
	Tree.insert(43);
	Tree.insert(21);
	Tree.insert(10);
	Tree.insert(89);
	Tree.insert(38);
	Tree.insert(69);
	
	Tree.display();
	Tree.remove(43);
	Tree.remove(88);
	Tree.remove(20);
	Tree.display();
	return 0;
}	
