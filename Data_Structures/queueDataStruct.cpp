#include<iostream>

using namespace std;

class Queue{
	int arr[5];
	int front;
	int rear;
	
	public:
		Queue(){
			front=-1;
			rear=-1;
			for(int i=0;i<5;i++){
				arr[i]=0;
			}
		}
		
		bool isEmpty(){
			if(front==-1 && rear == -1)
				return true;
			else
				return false;
		}
		
		
		bool isFull(){
			if(rear==4)
				return true;
			else
				return false;
		}
		
		void enqueue(int value){
			if(isFull()){
				cout<<"Queue is Full"<<endl;
				return;
			}
			else if(isEmpty()){
				rear=0;
				front=0;
				arr[rear]=value;
			}
			else{
				rear++;
				arr[rear]=value;
			}
		}
		
		int dequeue(){
			int x;
			if(isEmpty()){
				cout<<"Queue is Empty."<<endl;
				return 0;
			}
			else if(rear==front){
				x = arr[front];
				arr[front]=0;
				front =-1;
				rear=-1;
			}
			else{
				x=arr[front];
				front++;
			}
			return x;
				
		}
		
		int count(){
			return (rear-front+1);
		}
		
		void display(){
			cout<<"All items in the queue are: "<<endl;
			for(int i=0;i<5;i++){
				cout<<arr[i]<<" ";
			}
		}
};

int main()
{
	Queue q1;
	int option, value;
	do{
		cout<<"\n Enter operation you want to perform? Select option number. Enter 0 to exit."<<endl;
		cout<<"1. Enqueue()"<<endl;
		cout<<"2. Dequeue()"<<endl;
		cout<<"3. isEmpty()"<<endl;
		cout<<"4. isFull()"<<endl;
		cout<<"5. count()"<<endl;
		cout<<"6. display()"<<endl;
		cout<<"7. Clear screen"<<endl;
		
		cin>>option;
		switch(option){
			case 0:
				break;
			
			case 1:
				cout<<"Enqueue operation\n Enter an item to enqueue in the queue"<<endl;
				cin>>value;
				q1.enqueue(value);
				break;
			
			case 2:
				cout<<"Dequeue operation\n Dequeued value: "<<q1.dequeue()<<endl;
				break;
			
			case 3:
				if(q1.isEmpty())
					cout<<"Queue is empty."<<endl;
				else
					cout<<"Queue is not empty"<<endl;
				break;
			
			case 4:
				if(q1.isFull())
					cout<<"Queue is full."<<endl;
				else
					cout<<"Queue is not full"<<endl;
				break;
			
			case 5:
				cout<<"Count operation\nNo items in queue is: "<<q1.count()<<endl;
				break;
				
			case 6:
				cout<<"Display function called"<<endl;
				q1.display();
				break;
			
			case 7:
				system("cls");
				break;
				
			default:
				cout<<"Enter valid operation number!"<<endl;
				break;
		}
	}while(option!=0);
	
	return 0;
}