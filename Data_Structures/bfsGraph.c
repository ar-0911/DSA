#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct Queue{
	int size;
	int front;
	int rear;
	int arr[7];
};

typedef struct Queue queue;


void init(queue* q){
	q->front = -1;
	q-> rear = -1;
}

bool isEmpty(queue* q){
	if(q->front == -1 && q->rear == -1){
		return true;
	}
	else{
		return false;
	}
}
void enqueue(queue* q, int value){
	if(q->front == -1 && q->rear == -1){
		q->front = q->rear = 0;
		q->arr[q->rear] = value;
	}
	else{
		q->rear++;
		q->arr[q->rear] = value;
	}
}

int dequeue(queue* q){
	if(q->front == -1 && q->rear ==-1){
		printf("Queue is Empty.\n");
		return -1;
	}
	else if(q->front == q->rear){
		int dequeued = q->arr[q->front];
		q->front = q->rear = -1;
		return dequeued;
	}
	else{
		int dequeued = q->arr[q->front];
		q->front++;
		return dequeued;
	}
}

int main(){
	queue q1;
	queue* q;
	q=&q1;
	int first_node;
	init(q);
	int visited[7]={0,0,0,0,0,0,0};
	int adj_matrix[7][7]={
	{0,1,0,0,0,1,0},
	{1,0,1,0,0,0,0},
	{0,1,0,1,1,0,0},
	{0,0,1,0,1,0,0},
	{0,0,1,1,0,1,1},
	{1,0,0,0,1,0,1},
	{0,0,0,0,1,1,0},
	};
	printf("Enter node: ");
	scanf("%d",&first_node);
	printf("%d",first_node);
	visited[first_node] = 1;
	enqueue(q,first_node);
	while(!isEmpty(q)){
		int node = dequeue(q);
		for(int i=0;i<7;i++){
			if(adj_matrix[node][i]==1 && visited[i]==0){
				printf("%d", i);
				visited[i]=1;
				enqueue(q,i);
			}
		}
	}
	
	
}