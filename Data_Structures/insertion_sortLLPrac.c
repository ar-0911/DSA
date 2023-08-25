#include<stdlib.h>
#include<stdio.h>

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
	created_node->next= NULL;
	return created_node;
}

void insert_at_beg(int value){
	node* n = create_node(value);
	if(start == NULL){
		start = n;
	}
	else{
		n->next = start;
		start = n;
	}
}

void sorted_insert(node* n){
	if(sorted == NULL || sorted->data>n->data){
		n->next = sorted;
		sorted = n;
	}
	else{
		node* temp = sorted;
		while(temp->next != NULL && temp->next->data < n->data){
			temp= temp->next;
		}
		n->next = temp->next;
		temp->next = n;
	}
}

void insertion_sort(){
	node* current = start;
	while(current){
		node* next = current->next;
		sorted_insert(current);
		current = next;
	}
	start = sorted;
}

node* printList(){
	node* temp = start;
	while(temp){
		printf("%d-->",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	insert_at_beg(1);
	insert_at_beg(2);
	insert_at_beg(3);
	insert_at_beg(4);
	insert_at_beg(5);
	printList();
	insertion_sort();
	printList();
	return 0;
}
