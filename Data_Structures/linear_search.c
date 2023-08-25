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
	node* inserted_node = create_node(value);
	if(start==NULL){
		start = inserted_node;
	}
	else{
		inserted_node->next = start;
		start = inserted_node;
	}
}

bool linear_search(int value){
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

int main(){
	int value;
	insert_at_beg(12);
	insert_at_beg(2);
	insert_at_beg(45);
	insert_at_beg(1);
	insert_at_beg(22);
	display();
	printf("Enter value you want to search for: ");
	scanf("%d",&value);
	if(linear_search(value)){
		printf("ELement found in linked list.\n");
	}
	else{
		printf("Element not found in linked list.\n");
	}
}