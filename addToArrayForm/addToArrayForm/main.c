//���ڷǸ����� X ���ԣ�X ��������ʽ��ÿλ���ְ������ҵ�˳���γɵ����顣���磬��� X = 1231����ô��������ʽΪ [1,2,3,1]�������Ǹ����� X ��������ʽ A���������� X + K ��������ʽ��
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//

int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
	*returnSize = ASize;
	if (K == 0) {
		return A;
	}
	int count = 0;
	int yu = K, yu_copy = yu, ASize_copy = ASize;
	while (yu) {
		count++;
		yu /= 10;
	}
	int* tpr = (int*)malloc(sizeof(int) * count);
	int count_copy = count;
	while (yu_copy) {
		tpr[count_copy - 1] = yu_copy % 10;
		yu_copy /= 10;
		count_copy--;
	}
	if (count <= ASize) {
		count_copy = count;
		int i = ASize - 1;
		while (i) {
			if (count > 0) {
				A[i] += tpr[--count];
			}
			if (A[i] > 9) {
				A[i] -= 10;
				A[i - 1] += 1;
			}
			i--;
		}
		if (count_copy == ASize) {
			A[0] += tpr[0];
		}
		if (A[0]>9) {
			*returnSize = ASize + 1;
			int*tpr1 = (int*)malloc(sizeof(int)*(ASize + 1));
			for (i = 0; i<ASize; i++) {
				tpr1[i + 1] = A[i];
			}
			tpr1[0] = 1;
			tpr1[1] -= 10;
			return tpr1;
		}
		else {
			return A;
		}
	}
	else {
		int i = count - 1;
		*returnSize = count;
		while (i) {
			if (ASize_copy>0) {
				tpr[i] += A[--ASize_copy];
			}
			if (tpr[i] > 9) {
				tpr[i] -= 10;
				tpr[i - 1] += 1;
			}
			i--;
		}
		if (tpr[0]>9) {
			*returnSize = count + 1;
			int*tpr1 = (int*)malloc(sizeof(int)*(count + 1));
			for (i = 0; i<count; i++) {
				tpr1[i + 1] = tpr[i];
			}
			tpr1[0] = 1;
			tpr1[1] -= 10;
			return tpr1;
		}
		else {
			return tpr;
		}
	}
}


int main()
{
	int A[] = {1,2,0,0};
	int sz = sizeof(A) / sizeof(A[0]);
	int K =34;
	int returnSize = 0;
	int * ptr = addToArrayForm(A, sz, K, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", *(ptr + i));
	}
	system("pause");
	return 0;
}

