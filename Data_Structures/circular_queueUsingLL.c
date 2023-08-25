#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

typedef struct Node node;

node* front = NULL;
node* rear = NULL;

node* create_node(int value){
	node* created_node = (node*)malloc(sizeof(node));
	created_node->data = value;
	created_node->next = NULL;
	return created_node;
}

void enqueue(int value){
	node* n = create_node(value);
	if(rear == NULL && front == NULL){
		front = n;
		rear = n;
		rear->next = front;
	}
	else{
		rear->next = n;
		rear = n;
		n->next = front;
	}
}

int dequeue(){
	int dequeued;
	node* temp = front;
	if(front == NULL && rear == NULL){
		printf("Queue is Empty.\n");
		return -1;
	}
	else if(front == rear){
		dequeued = front->data;
		front = NULL;
		rear = NULL;
		free(temp);
	}
	else{
		dequeued = front->data;
		front = front->next;
		free(temp);
	}
	return dequeued;
}

void display(){
	node* temp = front;
	if(front == NULL && rear == NULL){
		printf("Queue is EMpty.\n");
	}
	else{
		do{
			printf("%d-->",temp->data);
			temp = temp->next;
		}while(temp!=rear->next);
	}
	printf("\n");
}

int main(){
	int choice,value;
	while(1){
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter value to enqueue: ");
				scanf("%d",&value);
				enqueue(value);
				break;
			case 2:
				printf("Dequeue value is %d\n", dequeue());
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid choice.\n");
		}
	}
	return 0;
}