#include<stdio.h>

static void insertion_sort(int arr[], int length){
	int i,j,key;
	for(i=1;i<length;i++){
		key = arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j-=1;
		}
		arr[j+1]=key;
	}
}


int main(){
	int arr[6]={4,88,1,22,33,5};
	insertion_sort(arr, 6);
	for(int i=0;i<6;i++){
		printf("%d\t", arr[i]);
	}
}