#include<stdio.h>
#include<limits.h>

// Max heap
//declaring heap globally
int heap[1000], heapsize;

//initializing heap
void Init(){
	heapsize = 0;
	heap[0] = INT_MAX;
}


// swap function
void swap(int index1,int index2){
	int temp = heap[index1];
	heap[index1] = heap[index2];
	heap[index2]=temp;
}

/*Inserting an element into the heap*/
void insert(int element){
	heapsize++;
	heap[heapsize] = element;
	int currentIndex = heapsize;
	while(heap[currentIndex/2]<element){
		heap[currentIndex] = heap[currentIndex/2];
		currentIndex/=2;
	}
	heap[currentIndex] = element;
}

/* deleting from heap */
void deleteFromHeap(){
	if(heapsize == 0){
		printf("Nothing to delete.\n");
		return;
	}
	// put last element into first index
	heap[1] = heap[heapsize];
	//deleting the last element
	heapsize--;
	int i=1;
	while(i<heapsize){
		int leftChildIndex = 2*i;
		int rightChildIndex = 2*i+1;
		if(leftChildIndex <= heapsize && heap[leftChildIndex]>heap[i]){
			swap(leftChildIndex,i);
			i = leftChildIndex;
		}
		else if(rightChildIndex <= heapsize && heap[rightChildIndex]>heap[i]){
			swap(rightChildIndex,i);
			i=rightChildIndex;
		}
		else{
			return;
		}
	}	
}

//printing
void hprint(){
	for(int i=1;i<=heapsize;i++){
		printf("%d ",heap[i]);
	}
	printf("\n");
}

void heapify(int arr[], int n, int i){
	int largest = i;
	int left = 2*i;
	int right = 2*i+1;
	if(left <= n && arr[largest]<arr[left]){
		largest = left;
	}
	if(right <= n && arr[largest] < arr[right]){
		largest = right;
	}
	if(largest != i){
		swap(largest,i);
		heapify(arr,n,largest);
	}
}

void heapsort(int arr[], int n){
	int size = n;
	while(size>1){
		swap(size,1);
		size--;
		heapify(arr,size,1);
	}
}

int main(){
	Init();
	insert(50);
	insert(55);
	insert(53);
	insert(52);
	insert(54);
	hprint();
	deleteFromHeap();
	hprint();
	int arr[6] = {-1,52,53,54,50,42};
	int n = 5;
	for(int i =n/2;i>0;i--){
		heapify(arr,n,i);
	}
}