#include<stdlib.h>
#include<stdio.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

typedef struct Node node;


node* create_node(int value){
	node* n = (node*)malloc(sizeof(node));
	n->data = value;
	n->left=NULL;
	n->right = NULL;
	return n;
}
node* buildTree(node* root){
	int data;
	printf("Enter node data: ");
	scanf("%d",&data);
	root = create_node(data);
	if(data==-1){
		return NULL;
	}
	printf("Enter data for inserting to left of %d\n",data);
	root->left = buildTree(root->left);
	printf("Enter data for inserting to right of %d\n",data);
	root->right = buildTree(root->right);
	return root;	
}

void preorder(node* root){
	if(root == NULL){
		return;
	}
	else{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node* root){
	if(root == NULL){
		return;
	}
	else{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
	
}

void postorder(node* root){
	if(root == NULL){
		return;
	}
	else{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
	
}

int main(){
	node* root = NULL;
	root = buildTree(root);
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
}