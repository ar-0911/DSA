#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
	return (a>b)?a:b;
}

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	int height;
};

int height(node* n){
	if(n==NULL){
		return 0;
	}
	else{
		return 1 + max(height(n->right,height(n->left)));
	}
}

node* create_node(int value){
	node* n = (node*)malloc(sizeof(node));
	n->data = value;
	n->left = NULL;
	n->right = NULL;
	n->height = 0;
	return n;
}

node* rightRotate(node* y){
	node* x = y->left;
	node* t2 = x->right;
	
	//after rotation
	x->right = y;
	y->left = t2;
	
	x->height = height(x);
	y->height = height(y);
	
	return x;
}

node* leftRotate(node* x){
	node* y = x->right;
	node* t2 = y->left;
	
	//after rotation
	y->left = x;
	x->right = t2;
	
	x->height = height(x);
	y->height = height(y);
	
	return y;
}

int balanceFactor(node* root){
	return height(root->left)-height(root->right);
}

node* insertIntoAvl(node* root,int value){
	if(root ==NULL){
		root = create_node(value);
		return root;
	}
	else if(value> root->data){
		root->right = insertIntoAvl(root->right,value);
	}
	else{
		root->left = insertIntoAvl(root->left,value);
	}
	root->height = height(root);
	int bf = balanceFactor(root);
	
}