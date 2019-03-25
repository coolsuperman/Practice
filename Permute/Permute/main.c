#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void swap (int *a, int* b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void go (int* nums , int start , int size , int** p , int* sum) {
	if ( start == size - 1 ) {
		p [*sum] = (int*)malloc (sizeof (int)*size);
		for ( int j = 0; j < size; j++ ) {
			p [*sum] [j] = nums [j];
		}
		(*sum)++;
		return;
	}
	for ( int i = start; i < size; i++ ) {
		swap (nums+i , nums+start );
		go (nums , start + 1 , size , p , sum);
		swap (nums + i , nums + start);
	}
}

int** permute (int* nums , int numsSize , int* returnSize) {
	int sum = 0;
	int** p = (int **)malloc (sizeof (int*) * 10000);
    go (nums , 0 , numsSize , p , &sum);
	*returnSize = sum;
	return p;
}

int main () {
	int nums[] = {1,2,3,4};
	int numsSize = sizeof (nums) / sizeof (nums [0]);
	int returnSize=0;
	int ** back = permute (nums , numsSize , &returnSize);
	for ( int i = 0; i < returnSize; i++ ) {
		for ( int j = 0; j < numsSize; j++ ) {
			printf (" %d " , *(*(back + i) + j));
		}
		printf ("\n");
	}
	system ("pause");
	return 0;
}