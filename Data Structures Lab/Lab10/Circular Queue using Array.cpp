#include <iostream>
using namespace std;

class CircularQueue{
	private:
		int size;
		int count;
		int front;
		int rear;
		int *array;
	public:
		CircularQueue(int size){
			this->size = size;
			array = new int[this->size];
			count=0;
			front = 0;
			rear = 0;
		}
		bool isFull(){
			if((front==size-1)||(front==0 && rear == size-1))
				return true;
			return false;
		}
		bool isEmpty(){
			if(count==0)
				return true;
			return false;
		}
		void InsertQueue(int el){
			if(isFull()){
				cout << "Queue is full.\n";
				return;
			}
			if(rear== size)
				rear = 1;
				
			rear= (rear+1)%size;
			array[rear]= el;
			count++;
		}
		int Dequeue(){
			if(isEmpty()){
				cout << "Queue is Empty.\n";
				return -1;
			}
			front= (front+1)%size;
			int x= array[front];
			return x;
		}
		void Display(){
			int i= front+1;
			cout << "Elements in queue : ";
			do{
				cout << array[i] << " ";
				i= (i+1)%size;
			}while(i!=(rear+1)%size);
			cout << endl;
		}
};

int main(){
	CircularQueue Q(6);
	Q.InsertQueue(1);
	Q.InsertQueue(5);
	Q.InsertQueue(3);
	Q.InsertQueue(4);
	Q.InsertQueue(7);
	
	Q.Display();
	cout << Q.Dequeue() << " Dequeued.\n";
	Q.InsertQueue(6);
	Q.Display();
	return 0;
}
