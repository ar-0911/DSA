#include<stdio.h>



static void swap(int arr[], int index1, int index2){
	int temp = arr[index1];
	arr[index1]=arr[index2];
	arr[index2]=temp;
}

static int partition(int arr[],int s,int e){
	int pivot = arr[e];
	int pindex = s;
	for(int i =s;i<e;i++){
		if(arr[i]<pivot){
			swap(arr,i,pindex);
			pindex++;
		}
	}
	swap(arr,pindex,e);
	return pindex;
}

static void quick_sort(int arr[], int s, int e){   // s = starting, e = ending
	if(s<e){
		int p = partition(arr,s,e);
		quick_sort(arr,s,p-1);
		quick_sort(arr,p+1,e);
	}
}

int main(){
	int arr[7]={77,66,55,44,33,22,11};
	printf("Array before sorting.\n");
	for(int i=0;i<7;i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
	quick_sort(arr, 0, 6);
	printf("Array after sorting.\n");
	for(int i=0;i<7;i++){
		printf("%d\t", arr[i]);
	}
	return 0;
}