#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

class LinkedList{
	private:
		node *head, *tail;
	public:
		LinkedList(){
			head= NULL;
			tail= NULL;
		}
		void Add_Note(int val){
			node* temp= new node;
			temp->data= val;
			temp->next= NULL;
			
			if(head==NULL){
				head=temp;
				tail=temp;
			}
			else{
				tail->next= temp;
				tail= tail-> next;
			}
		}
		
		void replace(int searchelement, int replacingelement){
			node* temp= head;
			bool check=false;
			while(temp!=NULL){
				if(temp->data==searchelement){
					temp->data= replacingelement;
					check=true;
					cout << "Value " << searchelement << " is updated with : " << temp->data << endl;
				}
				temp= temp->next;
			}
			if(!check)
				cout << "Value " << searchelement << " doesn't exists in linkedlist." << endl;
		}
};

int main(){
	LinkedList l1;
	l1.Add_Note(10);
	l1.Add_Note(5);
	l1.Add_Note(11);
	l1.Add_Note(12);
	l1.Add_Note(6);
	
	int num, newNum;
	cout << "Enter the number you want to search : ";
	cin >> num;
	cout << "Etner the replacing value for " << num << " : ";
	cin >> newNum;
	l1.replace(num, newNum);
	
	return 0;
}
