#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Swap (int* a , int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void AdjustDown (int arr[] , int size , int root) {
	while (1) {
	    int left = root * 2 + 1;
		if ( left >= size ) { return; }
		int max = left;
		int right = root * 2 + 2;
		if ( right < size&&arr[right]>arr[left]) {
			max = right;
		}
		if ( arr [root] > arr [max] ) {
			return;
		}
		Swap (arr + root , arr + max);
		root = max;
	}
}
void CreatBigHeap (int arry[] , int size) {
	for ( int i = ((size - 1) - 1) / 2; i >= 0; i-- ) {
		AdjustDown (arry , size , i);
	}
}
void HeapSort (int *arr,int size) {
	CreatBigHeap (arr , size);
	for ( int i = 0; i < size - 1; i++ ) {
		int t = arr [0];
		arr [0] = arr [size - 1 - i];
		arr [size - 1 - i] = t;
		AdjustDown (arr , (size - 1- i ), 0);
	}
}

int main () {
	int arr[] = {2,4,3,6,5,7,1,9,8,10};
	int size = sizeof (arr) / sizeof (arr [0]);
	HeapSort (arr , size);
	for ( int i = 0; i < size; i++ ) {
		printf (" %d " , arr [i]);
	}
	system ("pause");
	return 0;
}