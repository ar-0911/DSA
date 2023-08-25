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

void insert_at_beg(int value){
	node* node_to_insert = create_node(value);
	if(start == NULL){
		start = node_to_insert;
	}
	else{
		node_to_insert->next = start;
		start = node_to_insert;
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
			temp=temp->next;
		}
		temp->next = node_to_insert;
	}
}

void insert_at_index(int value, int index){
	if(index>number_of_elements()){
		printf("Invalid index.\n");
	}
	else if(index==number_of_elements()){
		insert_at_end(value);
	}
	else if(index==0){
		insert_at_beg(0);
	}
	else{
		node* temp = start;
		node* node_to_insert = create_node(value);
		for(int i=0;i<index-1;i++){
			temp = temp->next;
		}
		node_to_insert->next = temp->next;
		temp->next = node_to_insert;
	}
}

void delete_at_beg(){
	if(start==NULL){
		printf("Nothing to delete.\n");
	}
	else{
		node* temp = start;
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
			temp = temp->next;
		}
		temp->next = NULL;
	}
}

void delete_at_index(int index){
	if(start==NULL || index>number_of_elements()-1){
		printf("Nothing to delete.\n");
	}
	else if(index == 0){
		delete_at_beg();
	}
	else if(index == number_of_elements()-1){
		delete_at_end();
	}
	else{
		node* temp = start;
		for(int i=0;i<index-1;i++){
			temp = temp->next;
		}
		temp->next = temp->next->next;
	}
}

bool present_in_list(int value){
	bool present = false;
	if(start==NULL){
		return present;
	}
	node* temp = start;
	while(temp!=NULL){
		if(value == temp->data){
			present = true;
			break;
		}
		temp = temp->next;
	}
	return present;
}

void display(){
	if(start==NULL){
		printf("List is Empty.\n");
	}
	else{
		node* temp = start;
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int number_of_elements(){
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

int main(){
	insert_at_beg(1);
	insert_at_beg(2);
	insert_at_end(4);
	insert_at_index(5,1);
	delete_at_index(5);
	printf("%d\n",number_of_elements());
	display();
	return 0;
}