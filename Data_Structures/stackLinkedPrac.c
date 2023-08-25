#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

void push(int value){
	node* node_to_push = create_node(value);
	if(start == NULL){
		start = node_to_push;
	}
	else{
		node_to_push->next = start;
		start = node_to_push;
	}
}

int pop(){
	if(start == NULL){
		printf("Stack Underflow.\n");
		return 0;
	}
	else{
		node* temp = start;
		int popped = temp->data;
		start = temp->next;
		return popped;
	}
}

int peek(){
	node* temp = start;
	return temp->data;
}

void display(){
	if(start==NULL){
		printf("Stack is empty.\n");
	}
	else{
		node* temp = start;
		while(temp!=NULL){
			printf("%d\n", temp->data);
			temp=temp->next;
		}
		printf("\n\n");
	}
}

int main(){
	for(int i=0;i<5;i++){
		push(i);
	}
	display();
	printf("%d\n",peek());
	printf("%d\n",pop());
	printf("\n\n");
	pop();
	display();
}