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

node* solve(int inorder[], int postorder[], int* postorderIndex, int inorderSindex, int inorderEindex, int n){
	if(*postorderIndex<0 || inorderSindex>inorderEindex){
		return NULL;
	}
	
	int element = postorder[*postorderIndex];
	*postorderIndex = *postorderIndex-1;
	node* root1 = create_node(element);
	int position = findelement(inorder, element, n);
	root1->right = solve(inorder,postorder, postorderIndex, position+1, inorderEindex,n);
	root1->left = solve(inorder,postorder, postorderIndex, inorderSindex, position-1, n);
	
	return root1;
}

node* buildTree(int inorder[], int postorder[], node* root, int n){    // n = length of postorder and inorder array
	int postorderIndex = n-1;
	int* postOrd = &postorderIndex;
	node* ans = solve(inorder, postorder, postOrd, 0,n-1,n);
	return ans;
}

void postorder(node* root){
	if(root == NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

int main(){
	int inorder[]={4,8,2,5,1,6,3,7};
	int arrpostorder[] ={8,4,5,2,6,7,3,1};
	node* root = NULL;
	root = buildTree(inorder,arrpostorder,root,8);
	postorder(root);
	return 0;
}

