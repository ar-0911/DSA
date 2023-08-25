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
	node* temp = (node*)malloc(sizeof(node));
	temp->data = value;
	temp-> next = NULL;
	return temp;
}
bool isEmpty(){
	if(start==NULL){
		return true;
	}
	else{
		return false;
	}
}

void insert_at_beg(int value){
	node* node_to_insert = create_node(value);
	if(isEmpty()){
		start = node_to_insert;
	}
	else{
		node_to_insert->next = start;
		start = node_to_insert;
	}
}

int delete_at_beg(){
	if(isEmpty()){
		printf("List is empty.\n");
		return 0;
	}
	else{
		node* temp = start;
		int deleted = temp->data;
		start = temp->next;
		return deleted;
	}
}

void display(){
	if(isEmpty()){
		printf("List is Empty.\n");
	}
	else{
		node* temp = start;
		while(temp!=NULL){
			printf("%d",temp->data);
			temp=temp->next;
		}
	}
}


int main(){
	int value;
	printf("Enter value: ");
	scanf("%d",&value);
	int temp = value;
	while(temp>-1){
		if(temp==1){
			insert_at_beg(1);
			break;
		}
		else if(temp==0){
			insert_at_beg(0);
			break;
		}
		else{
			insert_at_beg(temp%2);
			temp = temp/2;
		}
	}
	printf("The binary value of %d is: ",value);
	display();
}