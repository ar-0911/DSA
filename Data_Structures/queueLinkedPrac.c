#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
typedef struct Node node;
node* start = NULL;


node* create_node(int value){
	node* created_node = (node*)malloc(sizeof(node));
	created_node->data = value;
	created_node->next = NULL;
	return created_node;
}

void enqueue(int value){
	node* node_to_enqueue = create_node(value);
	if(start == NULL){
		start = node_to_enqueue;
	}
	else{
		node* temp = start;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next = node_to_enqueue;
	}
}

int dequeue(){
	if(start==NULL){
		printf("Queue underflow.\n");
		return 0;
	}
	else{
		node* temp = start;
		int dequeued = temp->data;
		start = temp->next;
		return dequeued;
	}
}

void display(){
	if(start==NULL){
		printf("List is Empty.\n");
	}
	else{
		node* temp = start;
		while(temp!=NULL){
			printf("%d\t", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main(){
	for(int i=1;i<6;i++){
		enqueue(i);
	}
	display();
	printf("%d\n",dequeue());
	dequeue();
	display();
}