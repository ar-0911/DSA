#include<stdio.h>
#include<stdbool.h>

struct Queue{
	char arr[20];
	int front;
	int rear;
};

bool isFull(struct Queue q){
	if(q.rear == 19){
		return true;
	}
	else{
		return false;
	}
}

bool isEmpty(struct Queue q){
	if(front == -1 && rear == -1){
		return true;
	}
	else{
		return false;
	}
}

void enqueue(char person, struct Queue q){
	if(isFull(q)){
		printf("Queue overflow.\n");
	}
	else if(isEmpty(q)){
		q.front = 0;
		q.rear = 0;
	}
	else{
		q.rear++
	}
	q.arr[q.rear]=person;
}

char dequeue(struct Queue q){
	if(isEmpty(q)){
		printf("Queue underflow");
		return;
	}
	else if(q.front == q.rear){
		char dequeued = q.arr[q.front];
		q.front=-1;
		q.rear=-1
	}
	else{
		char dequeued = q.arr[q.front];
		q.front++;
	}
	return dequeued;
}

void count(struct Queue q){
	int children_count=0;
	int adult_count=0;
	for(int i=q.front;i<=q.rear;q++){
		if(q.arr[i]=='c'){
			children_count++;
		}
		else{
			adult_count++;
		}
	}
	printf("No of children: %d\nNo of Adults: %d.",children_count, adult_count);
}

void display(struct Queue q){
	for(int i=q.front;i<=q.rear;q++){
		printf("%c  ",q.arr[i]);
	}
	printf("\n");
}

int main(){
	struct Queue q1;
	enqueue('c', q1);
	printf("%c",dequeue(q1));
	return 0;
}