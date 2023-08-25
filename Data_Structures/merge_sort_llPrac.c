#include<stdlib.h>
#include<stdio.h>

struct Node{
	int data;
	struct Node* next;
};
typedef struct Node node;
node* start = NULL;

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

node* findMid(node* head){
	node* fast = head->next;
	node* slow = head;
	while(fast!=NULL){
		fast= fast->next;
		if(fast!= NULL){
			fast = fast->next;
			slow = slow->next;
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
	while(left!=NULL && right != NULL){
		if(left->data>right->data){
			temp->next = right;
			temp = right;
			right = right->next;
		}
		else{
			temp->next = left;
			temp =left;
			left =left->next;
		}
	}
	while(left!=NULL){
		temp->next = left;
		temp = left;
		left = left->next;
	}
	while(right!=NULL){
		temp->next = right;
		temp = right;
		right = right->next;
	}
	node* res = head2->next;
	return res;
}

node* mergeSort(node* llhead){
	node* head = llhead;
	if(head == NULL || head->next == NULL){
		return head;
	}
	node* left = head;
	node* mid = findMid(head);
	node* right = mid->next;
	mid->next = NULL;
	left = mergeSort(left);
	right = mergeSort(right);
	
	node* ans = merge(left,right);
	return ans;
}

node* printList(node* head){
	if(head == NULL){
		printf("nothing to print.\n");
	}
	else{
		node* temp = head;
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main(){
	insert_at_beg(1);
	insert_at_beg(2);
	insert_at_beg(3);
	insert_at_beg(4);
	insert_at_beg(5);
	printList(start);
	node* new_head = mergeSort(start);
	printList(new_head);
}