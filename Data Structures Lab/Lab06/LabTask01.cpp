#include <iostream>
#include <cassert> 
using namespace std;

struct node{
	int info;
	node* next;
};
class linkedlist{
	node *head, *tail;
	int count=0;
	public:
		linkedlist(){
			head= tail= NULL;
		}
		void AddnewNode(int el){
			node *temp= new node;
			temp->info= el;
			temp->next=	NULL;
			if(!head){
				head=tail=temp;
			}
			else{
				tail->next= temp;
				tail= tail->next;
			}
			count++;
		}
		void Display(){
			node *p= head;
			while(p!=NULL){
				cout << p->info << " ";
				p = p->next;
			}
			cout << endl;
		}
		int getCount(){
			return count;
		}
		node* gethead(){
			return head;
		}
};

linkedlist BuildOneTwoThree(){
	int n, number;
	linkedlist l1;
	cout << "How many values you want to enter?\n";
	cin >> n;
	cout << "\nEnter Numbers :\n";
	for(int i=0; i<n; i++){
		cin >> number;
		l1.AddnewNode(number);
	}
	return l1;
}

int GetNth(linkedlist l1, int check){
	if(check <0 || check >= l1.getCount()){
		cout << "Invalid Entry";
		exit(0);
	}
	node *p= l1.gethead();
	int i=0;
	while(true){
		if(p==NULL)	
			break;
		if(i==check){
			return p->info;
		}
		i++;
		p=p->next;
	}
	
}

void GetNthTest(){
	int check;
	linkedlist myList= BuildOneTwoThree();
	cout << "Enter the index that you want to search : ";
	cin >> check;
	int lastNode= GetNth(myList,check);
	cout << "The value at index " << check << " is : " << lastNode << endl;
}

int main(){
	GetNthTest();
	return 0;
}
