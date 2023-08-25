#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

typedef struct Node node;
node* top = NULL;

node* create_node(int value){
	node* created_node = (node*)malloc(sizeof(node));
	created_node->data = value;
	created_node->next = NULL;
	return created_node;
}

void push(int value){
	node* push_node = create_node(value);
	if(top==NULL){
		top = push_node;
	}
	else{
		push_node->next = top;
		top = push_node;
	}
}

int pop(){
	if(top==NULL){
		printf("Stack underflow.\n");
	}
	else{
		int popped = top->data;
		top = top->next;
		return popped;
	}
}

void display(){
	node* temp = top;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main(){
	for(int i=1;i<6;i++){
		push(i);
	}
	display();
	pop();
	display();
}