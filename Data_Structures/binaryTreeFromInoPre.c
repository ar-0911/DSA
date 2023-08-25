#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

typedef struct Node node;


node* create_node(int value){
	node* created_node = (node*)malloc(sizeof(node));
	created_node->data = value;
	created_node->left = NULL;
	created_node->right = NULL;
	return created_node;
}

int findelement(int arr[], int element, int n){
	for(int i=0;i<n;i++){
		if(arr[i]==element){
			return i;
		}
	}
	return -1;
}

node* solve(int inorder[], int preorder[], int* preorderIndex, int inorderSindex, int inorderEindex, int n){
	if(*preorderIndex>=n || inorderSindex>inorderEindex){
		return NULL;
	}
	
	int element = preorder[*preorderIndex];
	*preorderIndex = *preorderIndex+1;
	node* root1 = create_node(element);
	int position = findelement(inorder, element, n);
	root1->left = solve(inorder,preorder, preorderIndex, inorderSindex, position-1, n);
	root1->right = solve(inorder,preorder, preorderIndex, position+1, inorderEindex,n);
	
	return root1;
}

node* buildTree(int inorder[], int preorder[], node* root, int n){    // n = length of preorder and inorder array
	int preorderIndex = 0;
	int* preOrd = &preorderIndex;
	node* ans = solve(inorder, preorder, preOrd, 0,n-1,n);
	return ans;
}

void preorder(node* root){
	if(root == NULL){
		return;
	}
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

int main(){
	int inorder[]={3,1,4,0,5,2};
	int arrpreorder[] ={0,1,3,4,2,5};
	node* root = NULL;
	root = buildTree(inorder,arrpreorder,root,6);
	preorder(root);
	return 0;
}

