#include<stdio.h>
#include<stdbool.h>

struct Queue{
	char arr[20];
	int front;
	int rear;
};

bool isFull(struct Queue *q){
	if(q->rear == 19){
		return true;
	}
	else{
		return false;
	}
}

bool isEmpty(struct Queue *q){
	if(q->front == -1 && q->rear == -1){
		return true;
	}
	else{
		return false;
	}
}

void enqueue(char person, struct Queue *q){
	if(isFull(q)){
		printf("Queue overflow.\n");
	}
	else if(isEmpty(q)){
		q->front++;
		q->rear++;
		//printf("enqueue completed\n");
	}
	else{
		q->rear++;
		//printf("enqueue completed\n");
	}
	q->arr[q->rear]=person;
}

char dequeue(struct Queue *q){
	char dequeued;
	if(isEmpty(q)){
		printf("Queue underflow");
		return '\0';
	}
	else if(q->front == q->rear){
		dequeued = q->arr[q->front];
		q->front=-1;
		q->rear=-1;
	}
	else{
		dequeued = q->arr[q->front];
		q->front++;
	}
	return dequeued;
}

void count(struct Queue *q){
	int children_count=0;
	int adult_count=0;
	for(int i=q->front;i<=q->rear;i++){
		if(q->arr[i]=='c'){
			children_count++;
		}
		else if(q->arr[i]=='a'){
			adult_count++;
		}
	}
	printf("No of children: %d\nNo of Adults: %d",children_count, adult_count);
}

void display(struct Queue *q){
	for(int i=q->front;i<=q->rear;i++){
		printf("%c  ",q->arr[i]);
	}
	printf("\n");
}


void enqueueVIP(char VIP, struct Queue *q){
	q->rear++;
	for(int i=q->rear+1;i>=1;i--){
		if(q->rear==20){
			break;
		}
		q->arr[i]=q->arr[i-1];
	}
	q->arr[0]=VIP;
}
int main(){
	struct Queue q;
	struct Queue *q1;
	q1=&q;
	q1->front=-1;
	q1->rear=-1;
	char person;
	for(int i = 0; i<10;i++){
		printf("Enter person entering if child press c, if adult press a, if VIP press v: ");
		scanf("%c", &person);
		fflush(stdin);
		if(person == 'v'){
			enqueueVIP(person,q1);
		}
		else{
			enqueue(person,q1);
		}
	}
	count(q1);
	printf("\n");
	display(q1);
	return 0;
}