#include <stdio.h>
#include <stdlib.h>

// each node in the auxiliary heap
// would point to its original node
// at the original heap

typedef struct val{
	int key;
	int ind;
}val;

void swap(val * p, val * q){
	val tmp = *p;
	*p = *q;
	*q = tmp;
}

void heapifyUpMin(int index, val * arr){
	int i = index;
	while (i != 0){
		// it's in its place
		if (arr[i].key >= arr[i/2].key)
			break;
		swap(&arr[i], &arr[i/2]);
		i /= 2;
	}
}

void heapifyDownMin(int index, val * arr, int size){
	int i = index;
	while (2*i+1 < size){
		if (2*i+2 < size){
			if (arr[i].key <= arr[2*i+1].key && arr[i].key <= arr[2*i+2].key)
				return;

			if (arr[2*i+1].key < arr[2*i+2].key){
				swap(&arr[2*i+1], &arr[i]);
				i = 2*i+1;
			}
			else{
				swap(&arr[2*i+2], &arr[i]);
				i = 2*i+2;
			}
		}
		else{
			if (arr[i].key <= arr[2*i+1].key)
				return;

			swap(&arr[2*i+1], &arr[i]);
			i = 2*i+1;
		}
	}
}

// we want to print the k-th lowest
// elements in O(k*log(k))
// instead of classical O(n*log(n))

void kmininmal(int * minHeap, int n, int k){
	// 2k+2 is enough for the auxiliary minimum heap
	val * auxHeap = (val *)malloc((2 * k + 2) * sizeof(val));
	int size = 1;
	auxHeap[0].key = minHeap[0];
	auxHeap[0].ind = 0;

	for (int i = 0; i < k; i++){
		// add both sons of current minimum element
		if(auxHeap[0].ind * 2 + 1 < n){
			auxHeap[size].ind = auxHeap[0].ind * 2 + 1;
			auxHeap[size].key = minHeap[auxHeap[size].ind];
			heapifyUpMin(size, auxHeap);
			size++;

			if(auxHeap[0].ind * 2 + 2 < n){
				auxHeap[size].ind = auxHeap[0].ind * 2 + 2;
				auxHeap[size].key = minHeap[auxHeap[size].ind];
				heapifyUpMin(size, auxHeap);
				size++;
			}
		}
		// print / eject minimum element
		printf("%d-th lowest element is : %d\n", i+1, auxHeap[0].key);
		if(i+1 == k)
			break;
		auxHeap[0] = auxHeap[size-1];
		size--;
		heapifyDownMin(0, auxHeap, size);
	}
	free(auxHeap);
}

// example :
// k = 8
int main(){
	int heap[] = {1, 4, 2, 6, 5, 8, 10, 7, 9, 11};
	int size = sizeof(arr) / sizeof (int);
	kmininmal(heap, size, 8);
	return 0;
}
