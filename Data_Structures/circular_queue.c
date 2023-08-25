#include<stdio.h>
#include<stdbool.h>

struct c_queue{
	int arr[5];
	int front;
	int rear;
};

bool isFull(struct c_queue q){
	if((q.rear+1)%5==q.front){
		return true;
	}
	else{
		return false;
	}
}

bool isEmpty(struct c_queue q){
	if(q.front == -1 && q.rear == -1){
		return true;
	}
	else{
		return false;
	}
}

void enqueue(struct c_queue q, int value){
	if(isFull(q)){
		printf("Queue overflow.\n");
		return;
	}
	else if(isEmpty()){
		q.front = 0;
		q.rear = 0;
	}
	else{
		rear = (rear+1)%5;
	}
	q.arr[q.rear]=value;
}

int dequeue(struct c_queue q){
	int dequeued;
	if(isEmpty(q)){
		printf("queue underflow.\n");
		return 0;
	}
	else if(q.front == q.rear){
		dequeue = q.arr[q.front];
		q.front = -1;
		q.rear = -1;
	}
	else{
		q.front = (q.front+1)%5
		dequeued = q.arr[q.front];
	};
	return dequeued;
	
}
