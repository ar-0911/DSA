#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

typedef struct Node node;

node* front = NULL;
node* rear = NULL;

bool isEmpty(){
	if(front == NULL && rear == NULL){
		return true;
	}
	else{
		return false;
	}
}

node* create_node(int value){
	node* created_node = (node*)malloc(sizeof(node));
	created_node->data = value;
	created_node->next = NULL;
	return created_node;
}

void enqueue(int value){
	node* enqueue_node = create_node(value);
	if(isEmpty()){
		front= enqueue_node;
		rear= enqueue_node;
	}
	else{
		rear->next=enqueue_node;
		rear=enqueue_node;
	}
}

int dequeue(){
	if(isEmpty()){
		printf("Empty queue.\n");
		return 0;
	}
	else{
		int dequeued = front->data;
		front = front->next;
		return dequeued;
	}
}

void display(){
	if(isEmpty()){
		printf("Queue is Empty.\n");
	}
	else{
		node* temp = front;
		while(temp!=rear->next){
			printf("%d\t",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int no_of_elements(){
	int count = 0;
	node* temp = front;
	while(temp!= rear->next){
		count++;
		temp= temp->next;
	}
	return count;
}

int main(){
	int choice,value;
	while(1){
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Number of elements\n5.exit\n");
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
				printf("Number of elements: %d\n", no_of_elements());
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid choice.\n");
		}
	}
	return 0;
}