#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	int height;
};
typedef struct Node node;

int max(int a, int b){
	return (a > b)? a : b;
}

int height(node* n){
	if(n==NULL){
		return 0;
	}
	return 1+max(height(n->left),height(n->right));
	
}

node* create_node(int value){
	node* created_node =(node*)malloc(sizeof(node));
	created_node->data = value;
	created_node->left = NULL;
	created_node->right = NULL;
	created_node->height=0;
	return created_node;
}

int balanceFactor(node* n){
	if(n==NULL){
		return 0;
	}
	return height(n->left)-height(n->right);
}

node* rightRotate(node* y){
	node* x = y->left;
	node* T2 = x->right;
	
	//rotation
	x->right = y;
	y->left = T2;
	
	//updating heights
	x->height = height(x);
	y->height = height(y);
	
	return x;
}

node* leftRotate(node* x){
	node* y = x->right;
	node* T2 = y->left;
	
	//rotation
	y->left = x;
	x->right = T2;
	
	//updating heights
	x->height = height(x);
	y->height = height(y);
	
	return y;
}

node* insertIntoAvl(node* root, int value){
	
	if(root==NULL){
		root = create_node(value);
		return root;
	}
	if(value < root->data){
		root->left = insertIntoAvl(root->left,value);
	}
	else if(value>root->data){
		root->right = insertIntoAvl(root->right,value);
	}
	else{
		return root;
	}
	
	root->height = height(root);
	
	int balance = balanceFactor(root);
	
	//left left
	if(balance>1 && value < root->left->data){
		return rightRotate(root);
	}
	
	//right right
	if(balance < -1 && value > root->right->data){
		return leftRotate(root);
	}
	
	//left right
	if(balance > 1 && value > root->left->data){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
	//right left
	if(balance < -1 && value < root->right->data){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	
	return root;
	
}

void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
	
	struct Node *root = NULL;
 
  	root = insertIntoAvl(root, 10);
  	root = insertIntoAvl(root, 20);
  	root = insertIntoAvl(root, 30);
  	root = insertIntoAvl(root, 40);
  	root = insertIntoAvl(root, 50);
  	root = insertIntoAvl(root, 25);
  	
  	preOrder(root);
  	return 0;
 
}

 
