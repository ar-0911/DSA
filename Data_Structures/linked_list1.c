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

void insert_at_index(int index,int value){
	int end_index = no_of_elements()-1;
	if(index>end_index){
		printf("Node cannot be added at this position as the list is not big enough!\n");
	}
	/*else if(index==end_index+1){
		insert_at_end(value);
	}
	else if(index==0){
		insert_at_beg(value);
	}*/
	
	else{
		node* node_to_insert = create_node(value);
		node* temp = start;
		for(int i=0;i<index-1;i++){
			temp=temp->next;
		}
		node_to_insert->next = temp->next;
		temp->next=node_to_insert;
	}
}

void insert_at_middle(int value){
	int middle = no_of_elements()/2;
	insert_at_index(middle,value);
}

void insert_at_end(int value){
	node* temp = start;
	node* node_to_insert = create_node(value);
	if(start==NULL){
		start = node_to_insert;
	}
	else{
		while(temp->next!=NULL){   
		temp = temp->next;
		} 
		temp->next = node_to_insert;
	}
	
}

void delete_at_beg(){
	if(start==NULL){
		printf("deletion not possible.\n");
	}
	else{
		node* temp = start;
		temp = temp->next;
		start = temp;
	}
}

void delete_at_end(){
	if(start==NULL){
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
	node* temp = start;
	for(int i=0;i<index-1;i++){
		temp = temp->next;
	}
	temp->next = temp->next->next;
}

void display(){
	node* temp = start;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
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

int main(){
	insert_at_beg(5);
	insert_at_beg(11);
	insert_at_end(23);
	insert_at_end(34);
	insert_at_middle(25);
	display();
	delete_at_index(2);
	printf("no of elements: %d\n",no_of_elements());
	display();
	delete_at_beg();
	display();
	delete_at_end();
	display();
	return 0;
}