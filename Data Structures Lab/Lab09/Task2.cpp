#include <iostream>
using namespace std;

class QNode{
public:
	int data;
	QNode* next;
	QNode(){}
};

class Queue{
private:
	QNode *front, *rear;
public:
	Queue(){
		front = rear= NULL;
	}
	void Enqueue(int x){
		QNode *temp = new QNode;
		if(temp==NULL){
			cout << "Overflow heap.\n";
			exit(0);
		}
		else{
			temp->data= x;
			temp->next= NULL;
			if(front==NULL){
				front = rear = temp;
			}
			else{
				rear->next= temp;
				rear= temp;
			}
		}
	}
	int Dequeue(){
		int x= -1;
		if(isEmpty()){
			cout << "Queue is empty.\n";
		}
		else{
			QNode *p= front;
			front = front->next;
			x= p->data;
			delete p;
		}
		return x;
	}
	bool isEmpty(){
		if(front==NULL)
			return true;
		return false;
	}
	void Display(){
		QNode *p= front;
		while(p!=NULL){
			cout << p->data << " ";
			p= p->next;
		}
		cout << endl;
	}
	int CheckFront(){
		int x=-1;
		if(isEmpty()){
			cout << "Queue is empty.\n";
		}
		else{
			x= front->data;
		}
		return x;
	}
	int Size(){
		int count = 0;
		QNode *p= front;
		while(p!=NULL){
			count++;
			p= p->next;
		}
		return count;
	}
	
	void DeleteNegativeIntegers(){
		int x=-1;
		int c= Size();
		
		for(int i=0; i<c; i++){
			x= Dequeue();
			if(x>=0)
				Enqueue(x);
		}
	}
};

int main(){
	Queue q1;
	q1.Enqueue(1);
	q1.Enqueue(-2);
	q1.Enqueue(3);
	q1.Enqueue(-4);
	q1.Enqueue(-5);
	cout << "Before deleting negative numbers from queue : ";
	q1.Display();
	
	q1.DeleteNegativeIntegers();
	cout << "After deleting negative numbers from queue  : ";
	q1.Display();
	
	return 0;
}
