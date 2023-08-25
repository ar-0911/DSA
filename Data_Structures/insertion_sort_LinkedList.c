#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
};

typedef struct Node node;

node* start = NULL;

node* create_node(int value){
	node* created_node = (node*)malloc(sizeof(node));
	created_node->data = value;
	created_node->next = NULL;
	created_node->prev = NULL;
	return created_node;
}

void insert_at_beg(int value){
	node* node_to_insert = create_node(value);
	if(start == NULL){
		start = node_to_insert;
	}
	else{
		node_to_insert->next = start;
		start->prev = node_to_insert;
		start = node_to_insert;
	}
}

int no_of_elements(){
	int count = 0;
	node* temp = start;
	while(temp!=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

void display(){
	node* temp = start;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void insertion_sort(){
	node* temp = start;
	for(int i=1;i<no_of_elements()-2;i++){
		node* key = temp->next;
		node* check = temp->next->prev;
		while(temp->next->prev!=NULL && temp->next->next>key){
			
		}
	}
}