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

node* findMid(node* head){
	if(head == NULL){
		return NULL;
	}
	node* slow = head;
	node* fast = head->next;
	
	while(fast!=NULL){
		fast = fast->next;
		if(fast!= NULL){
			slow = slow->next;
			fast = fast->next;
		}
	}
	return slow;
}

node* merge(node* left, node* right){
	if(left == NULL){
		return right;
	}
	if(right == NULL){
		return left;
	}
	node* head2 = create_node(-1);
	node* temp = head2;
	while(left!=NULL && right !=NULL){
		if(left->data > right->data){
			temp->next = right;
			temp = right;
			right = right->next;
		}
		else{
			temp->next = left;
			temp = left;
			left= left->next;
		}
	}
	
	while(left!= NULL){
		temp->next = left;
		temp = left;
		left = left->next;
	}
	
	while(right!=NULL){
		temp->next = right;
		temp = right;
		right = right->next;
	}
	
	node* ans = head2->next;
	return ans;
}

node* merge_sort(node* ll_head){
	
	node* head = ll_head;	
	//base case
	if(head==NULL || head->next == NULL){
		return head;
	}
	
	node* mid  = findMid(head);
	node* left = head;
	node* right = mid->next;
	mid->next = NULL;
	
	left = merge_sort(left);
	right = merge_sort(right);
	
	node* result = merge(left,right);
	return result;
}

void printList(node* head){
	if(head == NULL){
		printf("List is Empty.\n");
	}
	else{
		node* temp = head;
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main(){
	insert_at_beg(23);
	insert_at_beg(21);
	insert_at_beg(54);
	insert_at_beg(1);
	insert_at_beg(72);
	printf("\tMERGE SORT\n");
	printf("list before sorting:\n");
	printList(start);
	node* new_head = merge_sort(start);
	printf("List after sorting:\n");
	printList(new_head);
	
}
