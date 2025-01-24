#include <iostream>
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
		head= tail= NULL;
		count=0;
	}
	void AddnewNode(int el){
		count++;
		node * temp= new node;
		temp->info=el;
		temp->next= NULL;
		if(!head){
			head= tail= temp;
		}
		else{
			tail->next= temp;
			tail= tail->next;
		}
	}
	
	void Display(){
		node *p=head;
		while(p!=NULL){
			cout << p->info << " ";
			p=p->next;
		}
		cout << endl;
	}
	
	void bubblesort(){
		for(int i=0; i<count-1; i++){
			node* c= head;
			node* prev= NULL;
			node* n;
			while(c && c->next){
				if(c->info > c->next->info){
					if(!prev){
						n= c->next;
						c->next= n->next;
						n->next=c;
						head= prev= n;
					}
					else{
						n=c->next;
						prev->next= n;
						c->next= n->next;
						n->next=c;
						prev=n;
					}
				}
				else{
					n=c->next;
					prev= c;
					c= n;
				}
			}
		}
	}
};

int main(){
	linkedlist l1;
	l1.AddnewNode(7);
	l1.AddnewNode(6);
	l1.AddnewNode(5);
	l1.AddnewNode(4);
	l1.AddnewNode(3);
	l1.AddnewNode(2);
	cout << "Data in linked list before sorting :\t";
	l1.Display();
	l1.bubblesort();
	cout << "Data in linked list after sorting :\t";
	l1.Display();
}
