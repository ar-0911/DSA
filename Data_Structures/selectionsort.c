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

void selection_sort(){
	node* temp = start;
	while(temp){
		node* min = temp;
		node* r = temp->next;
		while(r){
			if(min->data>r->data){
				min = r;
			}
			r = r->next;
		}
		int x = temp->data;
		temp->data = min->data;
		min->data = x;
		temp = temp->next;
	}
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
	insert_at_beg(12);
	insert_at_beg(24);
	insert_at_beg(69);
	insert_at_beg(3);
	insert_at_beg(72);
	printf("\tSELECTION SORT\n");
	printf("list before sorting: \n");
	display();
	printf("List after sorting: \n");
	selection_sort();
	display();
}