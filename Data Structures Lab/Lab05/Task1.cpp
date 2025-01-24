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
		
		int count(int val){
			int co=0;
			node* temp= head;
			while(temp!=NULL){
				if(temp->data==val)
				co++;
				temp=temp->next;
			}
			return co;
		}
};

int main(){
	LinkedList l1;
	l1.Add_Note(10);
	l1.Add_Note(5);
	l1.Add_Note(10);
	l1.Add_Note(20);
	
	int num;
	cout << "Enter the number you want to search : ";
	cin >> num;
	cout << "The number " << num << " appeared " << l1.count(num) << " times.\n";
	
	return 0;
}
