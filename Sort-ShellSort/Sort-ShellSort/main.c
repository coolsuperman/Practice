#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void InsertSortGap (int arr[] , int size , int gap) {//Ԥ�������
	for ( int i = gap; i<size; i++ ) {
		int k = arr [i];
		int j = 0;
		for ( j = i - gap; j >= 0; j -= gap ) {
			if ( arr [j] <= k ) {
				break;
			}
			else {
				arr [j + gap] = arr [j];
			}
		}
		arr [j + gap] = k;
	}
}
void ShellSort (int arr[] , int size) {//����
	int gap = size;
	while ( 1 ) {
		gap = gap / 3 + 1;//gap�Ƚϴ����->С->1ֹͣ��
		InsertSortGap (arr , size , gap);
		if ( gap == 1 ) {
			break;
		}
	}
}

int main () {
	int arr[] = { 4 , 2 , 6 , 4 , 3 , 10 , 5 , 8 , 3 , 6 , 9 };
	int size = sizeof (arr) / sizeof (arr [0]);
	ShellSort (arr , size);
	for ( int i = 0; i < size; i++ ) {
		printf (" %d " , arr [i]);
	}
	system ("pause");
	return 0;
}