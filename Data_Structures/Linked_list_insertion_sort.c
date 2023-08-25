#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// INSERTION SORT ALGO
//create an empty sorted list
// Traverse the given list, and do the following for every node
                  //Insert curretn node in sorted way in sorted or result list
// change head of givern linked list to head of sorted(or result) list

struct Node{
	int data;
	struct Node* next;
};

typedef struct Node node;

node* start = NULL;
node* sorted = NULL;


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

void sortedInsert(node* node_to_insert){
	if(sorted==NULL || sorted->data >= node_to_insert->data){
		node_to_insert->next = sorted;
		sorted = node_to_insert;
	}
	else{
		node* current = sorted;
		while(current->next!=NULL && current->next->data < node_to_insert->data){
			current = current->next;
		}
		node_to_insert->next = current->next;
		current->next = node_to_insert;
	}
}

void insertionSort(){
	node* current = start;
	while(current!=NULL){
		node* next = current->next;
		sortedInsert(current);
		current = next;
	}
	start = sorted;
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


int main(){
	insert_at_beg(32);
	insert_at_beg(11);
	insert_at_beg(90);
	insert_at_beg(54);
	insert_at_beg(46);
	
	printf("\tINSERTION SORT\t\n");
	printf("List before sorting:\n");
	display();
	printf("List after sorting:\n");
	insertionSort();
	display();
}