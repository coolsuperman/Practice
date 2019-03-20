#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Swap (int *a , int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void InsertSort (int* arr , int size) {
	for ( int i = 1; i < size; i++ ) {
		int k = arr [i];
		int j = 0;
		for ( j= i - 1; j >= 0; j-- ) {
			if ( arr[j] > k ) {//此处不可使用arr[i],因为会被覆盖；
				arr [j+ 1] = arr [j];
			}
			else {
				break;
			}
		}
		arr [j + 1] = k;
	}
}

void InsertSort_Binnary(int* arr , int size) {
	for ( int i = 1; i < size; i++ ) {
		int k = arr [i];
		int left = 0;
		int right = i - 1;
		while ( left <= right ) {
			int mid = (left+right )/ 2;
			if ( arr [mid] == arr [i] ) {
				break;
			}
			else if ( arr [mid] > arr [i] ) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}

		}
		int j = 0;
		if ( arr [left] < k ) {
			for ( j = i-1; j >= left + 1; j-- ) {
				arr [j + 1] = arr [j];
			}
			arr [left + 1] = k;
		}
		else {
			for ( j = i-1; j >=left; j-- ) {
				arr [j + 1] = arr [j];
			}
			arr [left] = k;
		}
		}
	}

int main () {
	int arr[] = { 4 , 2 , 6 , 4 , 3 , 10 , 5 , 8 , 3 , 6 , 9 };
	int size = sizeof (arr) / sizeof (arr [0]);
	InsertSort_Binnary (arr , size);
	for ( int i = 0; i < size; i++ ) {
		printf (" %d ",arr[i]);
	}
	system ("pause");
	return 0;
}