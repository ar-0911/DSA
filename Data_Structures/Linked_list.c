#include<stdlib.h>
#include<stdio.h>

struct Node{
	int data;
	struct Node* next;
};
typedef struct Node node;
node* start = NULL;

node* create_node(){
	node* created;
	created = (node*)malloc(sizeof(node));
	printf("Enter data for the node: ");
	scanf("%d", &created->data);
	created->next = NULL;
	return created;

}

void insert_at_beg(){
	node* beginning_node;
	beginning_node = create_node();
	if(start == NULL){
		start = beginning_node;
	}
	else{
		beginning_node->next = start;
		start = beginning_node;
	}
}

void insert_at_end(){
	node* ending_node;
	node* ptr;
	ending_node = create_node();
	ptr = start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next = ending_node;
}

void display(){
	if(start == NULL){
		printf("Empty list.\n");
	}
	else{
		node* ptr;
		ptr=start;
		while(ptr!=NULL){
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}
	}
}

int main(){
	for(int i=0;i<3;i++){
		insert_at_beg();
	}
	insert_at_end();
	display();
}