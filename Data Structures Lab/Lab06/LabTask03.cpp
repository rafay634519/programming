#include <iostream>
using namespace std;

struct node{
	int info;
	node* next;
};

class CircularLinkedList{
	node *head, *tail;
	public:
		CircularLinkedList(){
			head = tail = NULL;
		}
		void AddnewNodeAtTail(int el){
			node *temp= new node;
			temp->info= el;
			if(!head){
				head= temp;
				tail= temp;
				tail->next=head;
			}
			else{
				tail->next=temp;
				tail= tail->next;
				tail->next=head;
			}
		}
		void Display(){
			node *p= head;
			do{
				cout << p->info << " ";
				p= p->next;
			}while(p!=head);
			cout << endl;
		}
		
		void DeleteFromHead(){
			if(!head){
				cout << "can't delete from empty list\n";
				exit(0);
			}
			else{
				node *p=head, *temp;
				temp = head->next;
				tail->next= temp;
				head = temp;
				delete p;
			}
		}
		
		void DeleteFromTail(){
			node *p= head, *temp;
			if(!head){
				cout << "Can't delete from an empty linked list\n";
			}
			else{
				temp=head;
				head= head->next;
				tail->next=head;
				delete temp;
			}
		}
		
		void InsertAtHead(int el){
			node *temp= new node;
			temp->info= el;
			if(!head){
				head= temp;
				tail= temp;
				tail->next=head;
			}
			else{
				temp->next = head;
				head= temp;
				tail->next = temp;
			}
		}
		
};

int main(){
	CircularLinkedList l1;
	l1.AddnewNodeAtTail(5);
	l1.AddnewNodeAtTail(10);
	l1.AddnewNodeAtTail(15);
	l1.AddnewNodeAtTail(25);
	l1.AddnewNodeAtTail(30);
	l1.AddnewNodeAtTail(35);
	l1.AddnewNodeAtTail(40);
	cout << "Orignal values of nodes : \n";
	l1.Display();
	cout << "\nValues after inserting at head : \n";
	l1.InsertAtHead(1);
	l1.Display();
	cout << "\nValues after deleting head : \n";
	l1.DeleteFromHead();
	l1.Display();
	cout << "\nValues after deleting tail : \n";
	l1.DeleteFromTail();
	l1.Display();
	
	return 0;
}
