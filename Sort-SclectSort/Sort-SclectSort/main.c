#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void swap (int*a , int*b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void SelectSort (int* arr , int size) {//����ÿ��ѡ��С������O��n^2��O(1);���ȶ�
	for ( int i = 0; i<size; i++ ) {
		int min = i;//�����ʼ��������С�ģ�
		for ( int j = i + 1; j<size; j++ ) {
			if ( arr [j]<arr [min] ) {
				min = j;
			}
		}
		//������С���������ʵ�λ��[i]��
		swap (arr + min , arr + i);
	}
}
//˫��ѡ��
//�Ż���:һ�α����м�ѡ�����ѡ��С��
void SelectSortPlus (int* arr , int size) {//����ÿ��ѡ��С������O��n^2��O(1);���ȶ�
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
			max = min;//��ʱmax�Ѿ�����һ���������ˣ�
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