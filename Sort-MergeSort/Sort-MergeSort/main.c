#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void Merge (int *arr , int left , int mid , int right , int *extra) {
	int size = right - left;
	int left_index = left;
	int right_index = mid;
	int extra_index = 0;
	while ( left_index<mid&&right_index<right ) {
		if ( arr [left_index] <= arr [right_index] ) {
			extra [extra_index] = arr [left_index];
			left_index++;
		}
		else {
			extra [extra_index] = arr [right_index];
			right_index++;
		}
		extra_index++;
	}
	while ( left_index<mid ) {
		extra [extra_index++] = arr [left_index++];
	}
	while ( right_index<right ) {
		extra [extra_index++] = arr [right_index++];
	}
	for ( int i = 0; i<size; i++ ) {
		arr [left + i] = extra [i];//这里要放回原数据段，原数据段是从left处开始的；
	}
}
void __MergeSort (int arr[] , int left , int right , int *extra) {
	if ( right == left + 1 ) {//还剩一个数必有序；
		return;
	}
	if ( left >= right ) {//区间内没有数；
		return;
	}
	int mid = left + (right - left) / 2;//排序两个小区间；
	__MergeSort (arr , left , mid , extra);
	__MergeSort (arr , mid , right , extra);
	//左右两个小区间已经有序，开始合并；
	Merge (arr , left , mid , right,extra);
}
//[left,mid)[mid,right)
void MergeSort (int arr[] , int size) {
	int *extra = (int *)malloc (sizeof (int)*size);
	__MergeSort (arr , 0 , size , extra);
	free (extra);
}

void MergeSort_Nor (int arr[] , int size) {
	int *extra = (int *)malloc (sizeof (int)*size);
	for ( int i = 1; i<size; i *= 2 ) {//进行log2^size次，每次有i元素一组
		for ( int j = 0; j<size; j += 2 * i ) {
			int left = j;
			int mid = left + i;
			if ( mid >= size ) {
				break;
			}
			int right = mid + i;//[left,right)
			if ( right>size ) {
				right = size;
			}
			Merge (arr , left , mid , right , extra);
		}
	}
	free (extra);
}

int main () {
	int arr[] = { 2 , 4 , 3 , 6 , 5 , 7 , 1 , 9 , 8 , 10 };
	int size = sizeof (arr) / sizeof (arr [0]);
	void (*select[])(int* , int) = { MergeSort , MergeSort_Nor};
	select[0](arr , size);
	for ( int i = 0; i < size; i++ ) {
		printf (" %d " , arr [i]);
	}
	system ("pause");
	return 0;
}