#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

typedef struct Node node;

node* create_node(int value){
	node* n = (node*)malloc(sizeof(node));
	n->data = value;
	n->right = NULL;
	n->left = NULL;
}

node* insertIntoBST(node* root, int value){
	if(root == NULL){
		root = create_node(value);
	}
	else if(value>root->data){
		root->right = insertIntoBST(root->right,value);
	}
	else{
		root->left = insertIntoBST(root->left,value);
	}
	return root;
}

node* maxval(node* root){
	if(root == NULL){
		return NULL;
	}
	node* temp = root;
	while(temp->right!=NULL){
		temp = temp->right;
	}
	return temp;
}

node* minval(node* root){
	if(root == NULL){
		return NULL;
	}
	node* temp = root;
	while(temp->left !=NULL){
		temp = temp->left;
	}
	return temp;
}

node* deleteFromBst(node* root,int value){
	//base case
	if(root == NULL){
		return root;
	}
	if(root->data == value){
		//0 child
		if(root->left == NULL && root->right == NULL){
			free(root);
			return NULL;
		}
		
		//1 child
		//left child present
		if(root->left != NULL && root->right == NULL){
			node* temp = root->left;
			free(root);
			return temp;
		}
		
		//right child present
		if(root->right != NULL && root->right == NULL){
			node* temp = root->right;
			free(root);
			return temp;
		}
		
		//2child present
		if(root->right != NULL && root->left != NULL){
			int minimum= minval(root->right)->data;
			root->data = minimum;
			root->right = deleteFromBst(root->right,minimum);
			return root;
		}
	}
	else if(value>root->data){
		root->right = deleteFromBst(root->right,value);
		return root;
	}
	else{
		root->left = deleteFromBst(root->left,value);
		return root;
	}
}

bool searchInBst(node* root, int value){
	if(root == NULL){
		return false;
	}
	else if(root->data == value){
		return true;
	}
	else if(value>root->data){
		return searchInBst(root->right,value);
	}
	else{
		return searchInBst(root->left,value);
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

int height(node* root){
	if(root == NULL){
		return 0;
	}
	else{
		int lheight = height(root->left);
		int rheight = height(root->right);
		if(lheight>rheight){
			return lheight;
		}
		else{
			return rheight+1;
		}
	}
}


int main(){
	int data;
	printf("Enter data for root node: ");
	scanf("%d",&data);
	node* root=NULL;
	while(data!=(-1)){
		root=insertIntoBST(root,data);
		printf("Enter value to insert into binary search tree: ");
		scanf("%d",&data);
	}
	printf("%d",height(root));
	printf("\n");
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
}