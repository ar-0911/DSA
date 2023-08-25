#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void insert_at_index(int,int);
struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
};

typedef struct Node node;
node* start = NULL;

bool isEmpty(){
	if(start == NULL){
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
	created_node->prev = NULL;
	return created_node;
}

void insert_at_beg(int value){
	node* node_to_insert = create_node(value);
	if(start ==NULL){
		start = node_to_insert;
	}
	else{
		node* temp = start;
		node_to_insert->next = temp;
		temp->prev = node_to_insert;
		start = node_to_insert;
	}
}

void insert_at_end(int value){
	node* node_to_insert = create_node(value);
	if(isEmpty()){
		start = node_to_insert;
	}
	else{
		node* temp = start;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = node_to_insert;
		node_to_insert->prev = temp;
	}
}

void insert_at_index(int index, int value){
	if(index>no_of_elements()){
		printf("Index not found list too small.\n");
	}
	else{
		node* node_to_insert = create_node(value);
		node* temp = start;
		for(int i = 0;i<index-1;i++){
			temp = temp->next;
		}
		node_to_insert->next = temp->next;
		temp->next->prev = node_to_insert;
		node_to_insert->prev = temp;
		temp->next = node_to_insert;
	}
}

void delete_at_beg(){
	if(isEmpty()){
		printf("deletion not possible.\n");
	}
	else{
		node* temp = start;
		temp = temp->next;
		start = temp;
		temp->prev=NULL;	
	}
}

void delete_at_end(){
	if(isEmpty()){
		printf("deletion not possible.\n");
	}
	else{
		node* temp = start;
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		temp->next = NULL;
	}
}

void delete_at_index(int index){
	if(index>no_of_elements()-1){
		printf("index not found, deletion not possible.");
	}
	else if(index == no_of_elements()){
		delete_at_end();
	}
	else if(index == 0){
		delete_at_beg();
	}
	else{
		node* temp = start;
		for(int i=0;i<index-1;i++){
			temp = temp->next;
		}
		temp->next = temp->next->next;
		temp->next->prev = temp;
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
	if(isEmpty()){
		printf("List is empty.\n");
	}
	else{
		node* temp = start;
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

int main(){
	insert_at_beg(5);
	insert_at_beg(11);
	insert_at_beg(23);
	insert_at_end(37);
	insert_at_index(2,25);
	display();
	delete_at_index(2);
	display();
	delete_at_beg();
	display();
	delete_at_end();
	display();
	printf("the number of elements is %d\n",no_of_elements());
	display();
	return 0;
}