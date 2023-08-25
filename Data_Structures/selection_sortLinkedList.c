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

int no_of_elements(){
	int count = 0;
	node* temp = start;
	while(temp!=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

void selection_sort(){
	node* temp = start;
	for(int i=0;i<no_of_elements()-1;i++){
		node* min = temp;
		for(int j=i+1;j<no_of_elements();j++){
			node* temp1 = temp->next;
			if(min>temp1){
				min = temp1;
			}
		}
		if(min!= temp){
			temp = min;
		}
		temp = temp->next;
	}
}

void display(){
	node* temp = start;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main(){
	for(int i=5;i>0;i--){
		insert_at_beg(i);
	}
	display();
	selection_sort();
	display();
}