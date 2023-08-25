#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int visited[7]={0,0,0,0,0,0,0};

int adj_matrix[7][7]={
	{0,1,0,0,0,1,0},
	{1,0,1,0,0,0,0},
	{0,1,0,1,1,0,0},
	{0,0,1,0,1,0,0},
	{0,0,1,1,0,1,1},
	{1,0,0,0,1,0,1},
	{0,0,0,0,1,1,0},
};
	
void Depth_first_search(int i){
	printf("%d", i);
	visited[i]=1;
	for(int j = 0;j<7;j++){
		if(adj_matrix[i][j]==1 && visited[j]==0){
			Depth_first_search(j);
		}
	}
}

int main(){
	int num;
	printf("Enter node between 0 to 6 from where search should start: ");
	scanf("%d",&num);
	Depth_first_search(num);
}
