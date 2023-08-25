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


node* find_mid(node* start, node* last){
	
	if(start == NULL){
		return NULL;
	}
	node* fast = start;
	node* slow = start;
	while(fast!=last){
		fast = fast->next;
		if(fast!=last){
			fast = fast->next;
			slow = slow->next;
		}
	}
	return slow;
}

node* binary_search(int value){
	node* last = NULL;
	do{
		node* mid = find_mid(start, last);
		
		if(mid==NULL){
			return NULL;
		}
		if(mid->data == value){
			return mid;
		}
		
		else if(mid->data < value){
			start = mid->next;
		}
		else{
			last = mid;
		}
	}while(last !=NULL || last != start);
	
	return NULL;
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
	insert_at_beg(66);
	insert_at_beg(55);
	insert_at_beg(44);
	insert_at_beg(33);
	insert_at_beg(22);
	insert_at_beg(11);
	display();
	printf("Enter value you want to search for: ");
	scanf("%d",&value);
	if(binary_search(value)){
		printf("Element found in list\n");
	}
	else{
		printf("element not found.\n");
	}
}