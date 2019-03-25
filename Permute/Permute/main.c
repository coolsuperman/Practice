#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void swape (int i , int j , int* nums) {
	int tmp;
	tmp = nums [i];
	nums [i] = nums [j];
	nums [j] = tmp;
}

void per (int* nums , int start , int size , int** p , int* sum) {
	int i;
	if ( start == size - 1 ) {
		p [*sum] = (int*)malloc (sizeof (int) * size);
		for ( i = 0; i < size; i++ )
			p [*sum] [i] = nums [i];
		(*sum)++;
	}
	else {
		for ( i = start; i < size; i++ ) {
			swape (i , start , nums);
			per (nums , start + 1 , size , p , sum);
			swape (i , start , nums);
		}
	}
}

int** permute (int* nums , int numsSize , int* returnSize) {
	int sum = 0;
	int** p = (int **)malloc (sizeof (int*) * 10000);
	per (nums , 0 , numsSize , p , &sum);
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