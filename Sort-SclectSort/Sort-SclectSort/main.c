#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void swap (int*a , int*b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void SelectSort (int* arr , int size) {//降序，每次选最小的数；O（n^2）O(1);不稳定
	for ( int i = 0; i<size; i++ ) {
		int min = i;//假设最开始的数是最小的；
		for ( int j = i + 1; j<size; j++ ) {
			if ( arr [j]<arr [min] ) {
				min = j;
			}
		}
		//交换最小的数到合适的位置[i]；
		swap (arr + min , arr + i);
	}
}
//双向选择；
//优化版:一次遍历中既选最大又选最小；
void SelectSortPlus (int* arr , int size) {//降序，每次选最小的数；O（n^2）O(1);不稳定
	int minSpace = 0;
	int maxSpace = size - 1;
	while ( minSpace<maxSpace ) {
		int min = minSpace;
		int max = minSpace;
		for ( int j = minSpace + 1; j <= maxSpace; j++ ) {
			if ( arr [j]<arr [min] ) {
				min = j;
			}
			if ( arr [j]>arr [max] ) {
				max = j;
			}
		}
		swap (arr + min , arr + minSpace);
		if ( minSpace == max ) {
			max = min;//此时max已经被上一步交换走了；
		}
		swap (arr + max , arr + maxSpace);
		minSpace++;
		maxSpace--;
	}
}

int main () {
	int arr[] = { 4 , 2 , 6 , 4 , 3 , 10 , 5 , 8 , 3 , 6 , 9 };
	int size = sizeof (arr) / sizeof (arr [0]);
	SelectSortPlus (arr , size);
	for ( int i = 0; i < size; i++ ) {
		printf (" %d " , arr [i]);
	}
	system ("pause");
	return 0;
}