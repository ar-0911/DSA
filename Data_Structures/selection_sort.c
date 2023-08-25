#include<stdio.h>

static void selection_sort(int arr[], int length){
	int min;
	for(int i=0;i<length-1;i++){
		min = i;
		for(int j=i+1;j<length;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		
		if(min != i){
			int temp = arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
	}
}

int main(){
	int arr[5] = {64,25,12,22,11};
	selection_sort(arr, 5);
	for(int i=0;i<5;i++){
		printf("%d\t", arr[i]);
	}
	return 0;
}