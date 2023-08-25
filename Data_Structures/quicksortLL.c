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


struct Node* last_node(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}
 
struct Node* parition(struct Node* first, struct Node* last)
{
    struct Node* pivot = first;
    struct Node* front = first;
    int temp = 0;
    while (front != NULL && front != last) {
        if (front->data < last->data) {
            pivot = first;
 
            temp = first->data;
            first->data = front->data;
            front->data = temp;
 
            first = first->next;
        }
 
        front = front->next;
    }
 
    temp = first->data;
    first->data = last->data;
    last->data = temp;
    return pivot;
}
 
void quick_sort(struct Node* first, struct Node* last)
{
    if (first == last) {
        return;
    }
    struct Node* pivot = parition(first, last);
 
    if (pivot != NULL && pivot->next != NULL) {
        quick_sort(pivot->next, last);
    }
 
    if (pivot != NULL && first != pivot) {
        quick_sort(first, pivot);
    }
}

int main(){
	printf("\tQUICK SORT\n");
	insert_at_beg(12);
	insert_at_beg(1);
	insert_at_beg(33);
	insert_at_beg(22);
	insert_at_beg(4);
	insert_at_beg(72);
	insert_at_beg(9);
	printf("List before sorting: \n");
	display();
	printf("List after sorting:\n");
	quick_sort(start,last_node(start));
	display();

}