#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
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
	if(start==NULL){
		start = node_to_insert;
	}
	else{
		node* temp = start;
		node_to_insert->next = start;
		start = node_to_insert;
		temp->prev = node_to_insert;
	}
}

void insert_at_end(int value){
	node* node_to_insert = create_node(value);
	if(start==NULL){
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

void insert_at_index(int value,int index){
	if(start == NULL || index>no_of_elements()){
		printf("Insertion not possible.\n");
	}
	else if(index == no_of_elements()){
		insert_at_end(value);
	}
	else if(index==0){
		insert_at_beg(value);
	}
	else{
		node* node_to_insert = create_node(value);
		node* temp =start;
		for(int i=0;i<index-1;i++){
			temp = temp->next;
		}
		temp->next->prev = node_to_insert;
		node_to_insert->next = temp->next;
		node_to_insert->prev = temp;
		temp->next = node_to_insert;
	}
}

void delete_at_beg(){
	if(start==NULL){
		printf("Nothing to delete.\n");
	}
	else{
		node* temp = start;
		temp->next->prev = NULL;
		start = temp->next;
	}
}

void delete_at_end(){
	if(start==NULL){
		printf("Nothing to delete.\n");
	}
	else{
		node* temp = start;
		while(temp->next->next != NULL){
			temp= temp->next;
		}
		temp->next = NULL;
	}
}

void delete_at_index(int index){
	if(start == NULL || index>no_of_elements()){
		printf("deletion is not possible.\n");
	}
	else if(index==0){
		delete_at_beg();
	}
	else if(index==no_of_elements()-1){
		delete_at_end();
	}
	else{
		node* temp = start;
		for(int i =0 ;i<index-1;i++){
			temp = temp->next;
		}
		temp->next = temp->next->next;
		temp->next->prev = temp;
	}
}

int no_of_elements(){
	int count = 0;
	if(start == NULL){
		return count;
	}
	else{
		node* temp = start;
		while(temp!=NULL){
			count++;
			temp = temp->next;
		}
		return count;
	}
}

void display(){
	if(start==NULL){
		printf("List is Empty.\n");
	}
	else{
		node* temp = start;
		while(temp!=NULL){
			printf("%p\t%d\t%p\t%p\n",temp->prev,temp->data,temp->next,temp);
			temp = temp->next;
		}
	}
}

int main(){
	insert_at_beg(3);
	insert_at_beg(2);
	insert_at_beg(1);
	insert_at_end(5);
	insert_at_index(4,3);
	delete_at_index(3);
	display();
}