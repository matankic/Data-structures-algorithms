#include <stdio.h>
#include <stdlib.h>
#include "heap_sort.h"

void heapSort(int *arr, int n){
	buildMinHeap(arr, n);
	int * temp = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++){
		temp[i] = arr[0];
		deleteMin(arr, n - i); // size dynamically descends
	}
	for (int i = 0; i < n; i++)
		arr[i] = temp[i];
	free(temp);
	temp = NULL;
}

void buildMinHeap(int *arr, int n){
	int mid = n / 2; // no need of leaves' layer
	while (mid >= 0) { heapifyDown(arr, n - 1, mid--); }
}

void deleteMin(int *arr, int n){
	arr[0] = arr[n-1];
	heapifyDown(arr, n - 1, 0);
}

void heapifyDown(int *arr, int n, int index){
	int i = index, left, right;
	while (2*i + 1 < n){ // is there a left son
		left = 2*i + 1;
		if (2*i + 2 < n){ // is there a right son
			right = 2*i + 2;
			if (arr[right] < arr[left] && arr[right] < arr[i]){
				Swap(&arr[i], &arr[right]);
				i = 2*i + 2;
				continue;
			}
		}
		if (arr[left] < arr[i]){
			Swap(&arr[i], &arr[left]);
			i = 2*i + 1;
			continue;
		}
		break; // both left and right (if exist) sons are bigger than father;
	}
}

void Swap(int *p, int *q){
	int tmp = *p;
	*p = *q;
	*q = tmp;
}
