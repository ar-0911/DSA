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

node* middle(node* head_ref, node* last_ref){
	if(head_ref == NULL){
		return NULL;
	}
	node* slow = head_ref;
	node* fast = head_ref->next;
	
	if(fast!=last_ref){
		fast = fast->next;
		if(fast!=last_ref){
			slow = slow->next;
			fast = fast->next;
		}
	}
	return slow;
}

node* binarySearch(int value, node* head, node* last){
	
	node* head1 = head;
	node* last1 = last;
	
	node* mid = middle(head1, last1);
	
	if(mid == NULL){
		return NULL;
	}
	if(mid->data == value){
		return mid;
	}
	else if(mid->data > value){
		return binarySearch(value,mid->next, last1);
	}
	else{
		return binarySearch(value,head1,mid);
	}
}

node* lastNode(){
	node* temp = start;
	while(temp!= NULL && temp->next != NULL){
		temp = temp->next;
	}
	return temp;
}

int main(){
	for(int i=0;i<5;i++){
		insert_at_beg(i);
	}
	node* last = lastNode();
	if(binarySearch(4, start, last)!=NULL){
		printf("Found element in linked list.\n");
	}
	if(binarySearch(5,start,last) != NULL){
		printf("Element found in linked list.");
	}
	else{
		printf("Element found in linked list.");
	}
	return 0;
}