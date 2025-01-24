#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};

class stack{
	private:
		Node* top;
	public:
		stack();
		void push(int x);
		int pop();
		void Display();
		bool isEmpty();
		void Enqueue(int);
		int Dequeue();
};

stack:: stack(){
	top = NULL;
}

void stack:: push(int x){
	Node* temp = new Node;
	if(!temp){
		cout << "StackOverflow";
	}
	else{
		temp->data= x;
		temp->next= top;
		top= temp;
	}
}

int stack:: pop(){
	if(isEmpty()){
		cout << "\n Can't pop.\n";
		return -1;
	}
	else{
		Node* temp= top;
		top= top->next;
		int x= temp->data;
		delete temp;
		return x;
	}
}

bool stack:: isEmpty(){
	if(top==NULL){
		return true;
	}
	return false;
	
}

void stack:: Display(){
	Node* p= top;
	while(p!= NULL){
		cout << p->data << " ";
		p= p->next;
	}
	cout << endl;
}

void stack:: Enqueue(int x){
	stack s2;
	while(!this->isEmpty()){
		int c = this->pop();
		s2.push(c);
	}
	s2.push(x);
	
	while(!s2.isEmpty()){
		int c = s2.pop();
		push(c);
	}
}

int stack:: Dequeue(){
	return pop();
}

int main(){
	int num;
	
	stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	cout << "Elements already in stack : ";
	s1.Display();
	
	cout << "What do you want to insert? ";
	cin >> num;
	s1.Enqueue(num);
	
	cout << "Elements after enqueue : ";
	s1.Display();
	
	cout << "Dequeued element : " << s1.Dequeue() << endl;
	cout << "Final elements on stack (Reversed for queue): ";
	s1.Display();
	
	return 0;
}
