#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class LinkedList{
	private:
		node *head, *tail;
		int count;
	public:
		LinkedList(){
			head= tail= NULL;
			count=0;
		}
		void AddNewNode(int el){
			count++;
			node *temp= new node;
			temp->info= el;
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
			node *p =head;
			while(p!=NULL){
				cout << p->info << " ";
				p = p->next;
			}
			cout << endl;
		}
		
		void BubbleSort(){
			
			for(int i=0; i<count-1; i++){
				node *h = head;
				int swapped=0;
				for(int j=0; j<count-1-i; j++){
					node *p = h;
					node * q= p->next;
					if(p->info > q->info){
						swapped=1;
						int temp= p->info;
						p->info= q->info;
						q->info= temp;
					}
					h= h->next;
				}
			}
			Display();
		}
};

int main(){
	LinkedList l1;
	l1.AddNewNode(35);
	l1.AddNewNode(20);
	l1.AddNewNode(15);
	l1.AddNewNode(25);
	l1.AddNewNode(19);
	l1.AddNewNode(29);
	cout << "Data in linked list before swapping :\t";
	l1.Display();
	cout << "Data in linked list after swapping  :\t";
	l1.BubbleSort();
	return 0;
}
