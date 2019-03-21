#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Swap (int* a , int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int Parition_hoare (int *arr , int left , int right) {//hoare��
													  //������������
	int start = left;
	int end = right;//��׼ֵ��array[right]
	while ( start<end ) {
		//������ߣ�
		while ( start<end&&arr [start] <= arr [right] ) {//1��1��1��1��1���ӵ�����ѭ��
			start++;
		}
		//��߿�ס�ˣ����ұ�
		while ( start<end && arr [end] >= arr [right] ) {
			end--;
		}
		Swap (arr + start , arr + end);
	}//���䱻�ֳ�С���󣬻�׼��
	Swap (arr + start , arr + right);//��ʱstart�Ѿ������˴���С�ڵ��м�λ�ã�
	return start; //���ص�ǰ��׼ֵ����λ�ã�
}

int Parition_digit (int *arr , int left , int right) {//�ڿӷ�
													  //��һ��ʼ����������������
	int start = left;
	int end = right;
	int check = arr [right];//��׼ֵ��array[right]
	while ( start<end ) {
		while ( start<end&&arr [right] <= check ) {
			start++;
		}
		//�Ҳ��
		arr [end] = arr [start];
		while ( start<end&&arr [end] >= check ) {
			end--;
		}
		arr [start] = arr [end];
	}
	arr [start] = check; //���start��endָ��ͬһ���ط�
		return start; //���ص�ǰ��׼ֵ����λ�ã�
}

int Parition_FB (int *arr , int left , int right) {//ǰ��ָ�뷨
	int small = left;
	for ( int i = small; i < right; i++ ) {//�����ǲ�Ӱ�����ģ�
		if ( arr [i]<arr [right] ) {
			Swap (arr + small , arr + i);
			small++;
		}
	}
	Swap (arr + small , arr + right);
	return small;
}
//����ȡ�У�����ֵ���м���±ꣻ
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

void __QuickSort (int* arr , int left , int right) {//O(n*logN)��ֹ���� size == 0 || size == 1; left == right�� �����ڻ�ʣһ����; left > right ������û������
	if ( left >= right ) {
		return;
	}
	int (*slect[])(int* , int , int) = { Parition_hoare , Parition_digit , Parition_FB };
	int check_index = PickMid (arr , left , right);
	Swap (arr + check_index , arr + right);//����������ȥ��
	int div;//�Ȼ�׼ֵС�ķŻ�׼ֵ��ߣ���ķ��ұߣ���׼ֵ���ڵ��±�
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