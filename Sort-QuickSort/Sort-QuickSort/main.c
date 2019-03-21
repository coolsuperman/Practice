#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Swap (int* a , int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int Parition_hoare (int *arr , int left , int right) {//hoare法
													  //基在右左先走
	int start = left;
	int end = right;//基准值是array[right]
	while ( start<end ) {
		//先走左边；
		while ( start<end&&arr [start] <= arr [right] ) {//1，1，1，1，1不加等于死循环
			start++;
		}
		//左边卡住了，走右边
		while ( start<end && arr [end] >= arr [right] ) {
			end--;
		}
		Swap (arr + start , arr + end);
	}//区间被分成小，大，基准；
	Swap (arr + start , arr + right);//此时start已经到达了大于小于的中间位置；
	return start; //返回当前基准值所在位置；
}

int Parition_digit (int *arr , int left , int right) {//挖坑法
													  //坑一开始在最右所以左先走
	int start = left;
	int end = right;
	int check = arr [right];//基准值是array[right]
	while ( start<end ) {
		while ( start<end&&arr [right] <= check ) {
			start++;
		}
		//右侧坑
		arr [end] = arr [start];
		while ( start<end&&arr [end] >= check ) {
			end--;
		}
		arr [start] = arr [end];
	}
	arr [start] = check; //最后start与end指向同一个地方
		return start; //返回当前基准值所在位置；
}

int Parition_FB (int *arr , int left , int right) {//前后指针法
	int small = left;
	for ( int i = small; i < right; i++ ) {//等于是不影响分组的；
		if ( arr [i]<arr [right] ) {
			Swap (arr + small , arr + i);
			small++;
		}
	}
	Swap (arr + small , arr + right);
	return small;
}
//三数取中，返回值在中间的下标；
int PickMid (int*arr , int left , int right) {
	int mid = left + (right - left) / 2;
	if ( arr [left]>arr [right] && arr [left]> arr[mid] ) {
		return arr [mid]>arr [right] ? mid : right;
	}
	else if ( arr [mid]>arr [right] ) {
		return arr [right]>arr [left] ? right : left;
	}
	else {
		return arr [mid]>arr [left] ? mid : left;
	}
}

void __QuickSort (int* arr , int left , int right) {//O(n*logN)终止条件 size == 0 || size == 1; left == right； 区间内还剩一个数; left > right 区间内没有数；
	if ( left >= right ) {
		return;
	}
	int (*slect[])(int* , int , int) = { Parition_hoare , Parition_digit , Parition_FB };
	int check_index = PickMid (arr , left , right);
	Swap (arr + check_index , arr + right);//交换到最右去；
	int div;//比基准值小的放基准值左边，大的放右边，基准值所在的下标
	div = slect [0] (arr , left , right);
	__QuickSort (arr , left , div - 1);
	__QuickSort (arr , div + 1 , right);
}
void QSort (int* arr , int size) {
	__QuickSort (arr , 0 , size - 1);
}

int main () {
	int arr[] = { 2 , 4 , 3 , 6 , 5 , 7 , 1 , 9 , 8 , 10 };
	int size = sizeof (arr) / sizeof (arr [0]);
	QSort (arr , size);
	for ( int i = 0; i < size; i++ ) {
		printf (" %d " , arr [i]);
	}
	system ("pause");
	return 0;
}