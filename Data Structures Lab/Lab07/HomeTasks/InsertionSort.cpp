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
		node* getHead(){
			return head;
		}
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
		
		void Display(node* ans){
			while(ans){
				cout << ans->info << " ";
				ans= ans->next;
			}
			cout << endl;
		}
		
		node* insertionSortLinkedList(node* head)
		{
		    node *curr = head;
		    node *sorted_head = NULL;
		    while (curr != NULL)
		    {
		        node *currNext = curr->next;
		        sorted_head = sortedInsert(sorted_head,curr);
		        curr = currNext;
		    }
		    return sorted_head;
		}
		
		node* sortedInsert(node* sorted_head, node* new_node)
		{
		    // Insertion at first position
		    if(sorted_head == NULL || head->info >= new_node->info)
		    {
		        new_node->next = sorted_head;
		        return new_node;
		    }
		    else
		    {
		        node *curr = sorted_head;
		        while(curr->next != NULL && curr->next->info < new_node->info)
		            curr = curr->next;
		        new_node->next = curr->next;
		        curr->next = new_node;
		    }
		    return sorted_head;
		}
		
		void InsertionSort(int Array[], int size){
			for(int i=1; i<size; i++){
				int j=i-1;
				int x= Array[i];
				while(j>-1 && Array[j]>x){
					Array[j+1]=Array[j];
					j--;
				}
				Array[j+1]=x;
			}
			
			print(Array,size);
		}
		
		void InsertionSort(int size){
			node* p=head;
			node* q=p->next;
			
			while(q){
				
				node* temp= q;
				while(p.info > temp.info){
					q->next=q;
				}
			}
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
	node* p = l1.getHead();
	node* ans= l1.insertionSortLinkedList(p);
	l1.Display(ans);
	return 0;
}
