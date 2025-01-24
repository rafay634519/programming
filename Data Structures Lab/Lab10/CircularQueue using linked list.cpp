#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

class CircularQueue{
	private:
		node* front, *rear;
		int count;
		int size;
	public:
		CircularQueue(int size){
			this->size = size;
			count=0;
			front = rear = NULL;
		}
		void Enqueue(int el){
			node* temp = new node;
			if(!temp){
				cout << "heap is full, i.e. Queue is full.\n";
				return;
			}
			temp->data =el;
			
			if(front==NULL)
				front = temp;
			else
				rear->next = temp;
				
			rear = temp;
			rear->next = front;
			count++;
		}
		int Dequeue(){
			count--;
			if(isEmpty()){
				cout << "Queue is empty\n";
				return -1;
			}
			else{
				int x;
				if(front == rear){
					x= front->data;
					delete front;
					front = rear = NULL;
				}
				else{
					node* temp = front;
					x= front->data;
					front = front->next;
					rear->next = front;
					delete temp;
				}
				return x;
			}
		}
		bool isEmpty(){
			return (front==NULL) ? true: false;
		}
		void Display(){
			node* temp = front;
			cout << "Elements in queue : ";
			while(temp->next!= front){
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << temp->data << endl;
		}
};

int main(){
	CircularQueue Q1(5);
	Q1.Enqueue(1);
	Q1.Enqueue(5);
	Q1.Enqueue(3);
	Q1.Enqueue(4);
	Q1.Enqueue(7);
	Q1.Display();
	
	cout << Q1.Dequeue() << " dequeued.\n";
	Q1.Display();
	return 0;
}
