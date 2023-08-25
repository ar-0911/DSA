#include<stdio.h>
#include<stdbool.h>

struct Queue{
	char arr[20];
	int front;
	int rear;
};

bool isFull(struct Queue q){
	int length_arr = sizeof(q.arr)/sizeof(q.arr[0]);
	if(q.rear = length_arr-1){
		return true;
	}
	else{
		return false;
	}
}

bool isEmpty(struct Queue q){
	if(q.front==-1 && q.rear==-1){
		return true;
	}
	else{
		return false;
	}
}

void enqueue(char value, struct Queue q){
	if(isFull(q)){
		printf("Queue overflow.\n")
		return;
	}
	else if(isEmpty(q)){
		q.front = 0;
		q.rear = 0;
	}
	else{
		q.rear++;
	}
	q.arr[q.rear]=value;
}

char dequeue(struct Queue q){
	char dequeued;
	if(isEmpty(q)){
		printf("Stack underflow.\n");
		return;
	}
	else if(q.front == q.rear){
		dequeued = q.arr[q.front];
		q.front =-1;
		q.rear = -1
	}
	else{
		dequeued = q.arr[q.front];
		q.front++;
	}
	
}

void display(struct Queue q){
	for(int i=0;i<(sizeof(q.arr)/sizeof(q.arr[0]));i++){
		printf("%d\t",q.arr[i]);
	}
}

int main(){
	
	
	return 0;
}

