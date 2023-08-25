#include<stdio.h>
#include<stdlib.h>


void swap(int arr[], int index1 , int index2){
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

int partition(int arr[], int s, int e){
	int pivot = arr[e];
	int pindex = s;
	for(int i=s;i<e;i++){
		if(arr[i]<pivot){
			swap(arr,i,pindex);
			pindex++;
		}
	}
	swap(arr,pindex,e);	
	return pindex;
}

void quicksort(int arr[], int s,int e){
	if(s<e){
		int p = partition(arr,s,e);
		quicksort(arr,s,p-1);
		quicksort(arr,p+1,e);
	}
}


int main(){
	int arr[10];
	for(int i=0;i<10;i++){
		printf("Enter student GPA: ");
		scanf("%d",&arr[i]);
	}
	
	printf("Before sorting.\n");
	for(int i=0;i<10;i++){
		printf("%d\t",arr[i]);
	}
	
	printf("\n");
	
	quicksort(arr,0,9);
	
	printf("After sorting.\n");
	for(int i=0;i<10;i++){
		printf("%d\t", arr[i]);
	}
	printf("\n\n");
}