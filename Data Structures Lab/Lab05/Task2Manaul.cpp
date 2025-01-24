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
		
		void Average(LinkedList l2){
			node *temp, *n;
			
			int i=0;
			int avg=0, sum=0;
			temp=head;
			
			n=temp;
			while(temp->next->next->next != NULL){
				for(int i=0; i<4; i++){
					sum += temp->data;
					temp= temp->next;
				}
				avg=sum/4.0;
				sum=0;
				cout << avg << " ";
				l2.Add_Note(avg);
				n=n->next;
				temp=n;
				
			}	
		}
};

int main(){
	LinkedList l1, l2;
	
	int num;
	for(int i=0; i<12; i++){
		cout << "Enter an integer : ";
		cin >> num;
		l1.Add_Note(num);
	}
	l1.Average(l2);
	return 0;
}
