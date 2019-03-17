//二叉堆的定义与构建
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Datatype;
typedef struct Heap {
	Datatype arr[100];
	int size;
}Heap;//二叉堆定义；

void AdjustDown (int*arr , int size , int root) { 
	while ( 1 ) { 
		int left = root * 2 + 1;
		if ( left >= size ) { 
			return;
		}
		int right = root * 2 + 2;
		int min = left;
		if ( right<size&&arr [left]>arr [right] ) { 
			min = right;
		}
		if ( arr [root] < arr [min] ) { 
			return;
		}
		int temp = arr [min];
		arr [min] = arr [root];
		arr [root] = temp;
		root = min;
	}
}

int* CreatHeapTree (Datatype* arry , int size) {
	for ( int i = ((size - 1) - 1) / 2; i >= 0; i-- ) {
		AdjustDown (arry , size , i);
	}
	return arry;
}//最后一个非叶子节点开始

void HeapInit (Heap*heap , int* arr , int size) {
	memcpy (heap->arr , arr , size*sizeof (Datatype));
	heap->size = size;
	CreatHeapTree (heap->arr , size);
}

void AdjustUp (int* arry , int size , int child) { 
	while ( child ) { 
		int parent = (child - 1) / 2;
		if ( arry [parent] <= arry [child] ) { 
			return;
		}
		int temp = arry [child];
		arry [child] = arry [parent];
		arry[parent] = temp;
		child = parent;
	}
}

void HeapPush (Heap*heap , int val) {
	heap->arr [heap->size++] = val;
	AdjustUp (heap->arr , heap->size , heap->size - 1);
}

void HeapPop (Heap*heap) { 
	heap->arr [0] = heap->arr [heap->size - 1];
	AdjustDown (heap->arr , heap->size - 1 , 0);
	heap->size--;
}

int HeapTop (Heap*heap) {
	return heap->arr [0];
}
int main () {
	int arr[] = { 7 , 1 , 5 , 8 , 9 , 2 , 3 , 10 };
	int size = sizeof (arr) / sizeof (arr [0]);
	Heap heap;
	HeapInit (&heap , arr , size);
	HeapPush (&heap ,12);
	HeapPop (&heap);
	printf ("%d" , HeapTop (&heap));
	system ("pause");
	return 0;
}