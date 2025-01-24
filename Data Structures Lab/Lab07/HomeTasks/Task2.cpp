#include <iostream>
#include <conio.h>
using namespace std;

struct node{
	int info;
	node *next;
};

class linkedlist{
	node *head, *tail;
	int count;
	public:
		linkedlist(){
			head = tail = NULL;
			count=0;
		}
		void AddNewNode(int el){
			count++;
			node *temp = new node;
			temp->info= el;
			temp->next = NULL;
			if(!head){
				head = tail = temp;
			}
			else{
				tail->next= temp;
				tail= tail->next;
			}
		}
		void Display(){
			node *p= head;
			while(p!=NULL){
				cout << p->info << " ";
				p= p->next;
			}
			cout << endl;
		}
		
		void SelectionSort(){
			node* minNode;
			for(node *p= head; p->next!=NULL; p=p->next){
				int min= p->info;
				
				for(node *q= p; q!=NULL; q= q->next){
					if(q->info < min){
						min= q->info;
						minNode= q;
					}
				}
				if(p==head){	// SWAP FROM HEAD
					node* n1= p->next, *n2= minNode->next;
					node* t= head;
					node* p1= head;
					while(p1->next!=minNode){
						p1=p1->next;
					}
					head= minNode;
					minNode->next= n1;
					p1->next=p;
					p->next=n2;
				}
				else if(p->next->info == minNode->info){
					SwapAdjacent(p,minNode);
				}
				else{
					SwapNodes(p,minNode);
				}
				p=minNode;
			}
		}
		
		void SwapNodes(node* t1, node* t2){
			node* p1 = head;
			while(p1 && p1->next!=t1){
				p1=p1->next;
			}
			node* n1= t1->next;
			node* n2= t2->next;
			
			node* p2= head;
			while(p2 && p2->next!=t2){
				p2= p2->next;
			}
			
			p1->next = t2;
			t2->next = n1;
			p2->next = t1;
			t1->next = n2;
		}
		
		void SwapAdjacent(node* t1, node* t2){
			node* p= head;
			while(p->next != t1 && p){
				p=p->next;
			}
			node* te= t2->next;
			p->next = t2;
			t2->next = t1;
			t1->next = te;
		}
};

int main(){
	linkedlist l1;
	l1.AddNewNode(8);
	l1.AddNewNode(6);
	l1.AddNewNode(3);
	l1.AddNewNode(10);
	l1.AddNewNode(9);
	l1.AddNewNode(4);
	l1.AddNewNode(12);
	l1.AddNewNode(5);
	l1.AddNewNode(2);
	l1.AddNewNode(7);
	cout << "Data in linked list before sorting :\t";
	l1.Display();
	l1.SelectionSort();
	cout << "Data in linked list after sorting :\t";
	l1.Display();
	
	return 0;	
}
