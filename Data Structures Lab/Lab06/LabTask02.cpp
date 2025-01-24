#include <iostream>
using namespace std;

struct node{
	int info;
	node *prev;
	node *next;
};

class Doublylinkedlist{
	node *head, *tail;
	int count;
	public:
		Doublylinkedlist(){
			count=0;
			head=tail=NULL;
		}
		void AddNewNode(int el){
			count++;
			node *temp= new node;
			temp->info=el;
			temp->prev=NULL;
			temp->next=NULL;
			if(head==NULL){
				head= tail= temp;
			}
			else{
				tail->next= temp;
				temp->prev=tail;
				tail= tail->next;
			}
		}
		
		void Display(){
			node *p = head;
			while(p!=NULL){
				cout << p->info << " ";
				p=p->next;
			}
			cout << endl;
		}
		
		void HijackCabin(){
			node *temp= head;
			int i=1, flag=0;
			while(temp->next!=NULL){
				if(temp->info==0){
					cout << "Cabin " << i << " is hijacked" << endl;
					flag=1;
					break;
				}
				else if(temp->next->next==NULL){
					if(temp->next->info==0){
						cout << "Cabin " << i+1 << " is hijacked" << endl;
						flag=1;
						break;
					}
				}
				i++;
				temp= temp->next;
				
			}
			if(!flag)
				cout << "No cabin is hijacked.\n";
			
			while(temp->prev!=NULL){
				temp = temp->prev;
			}
			i=1; flag=0;
			while(temp!=NULL){
				if(temp->info == -1){
					cout << "Last member is hiding in " << i << " cabin.\n";
					flag=1;
					break;
				}
				i++;
				temp= temp->next;
			}
			if(!flag)
				cout << "Last member is not hiding in any train.\n";
		}
};

int main(){
	int n, number;
	Doublylinkedlist l1;
	cout << "How many values you want to enter? \t";
	cin >> n;
	cout << "Enter values :\n";
	for(int i=0; i<n; i++){
		cin >> number;
		l1.AddNewNode(number);
	}
	l1.HijackCabin();
	return 0;
}
