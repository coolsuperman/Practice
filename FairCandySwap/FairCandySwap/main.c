//����˿�ͱ����в�ͬ��С���ǹ�����A[i] �ǰ���˿ӵ�еĵ� i ���ǵĴ�С��B[j] �Ǳ���ӵ�еĵ� j ���ǵĴ�С����Ϊ���������ѣ����������뽻��һ���ǹ������������������Ƕ�����ͬ���ǹ���������һ����ӵ�е��ǹ�����������ӵ�е��ǹ�����С���ܺ͡�������һ���������� ans������ ans[0] �ǰ���˿���뽻�����ǹ����Ĵ�С��ans[1] �� Bob ���뽻�����ǹ����Ĵ�С������ж���𰸣�����Է��������κ�һ������֤�𰸴��ڡ�
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize)
{
	*returnSize = 2;
	int i = 0, sumA = 0, sumB = 0, chaAver = 0;
	int* ans = (int*)malloc(sizeof(int) * 2);
	for (i = 0; i<ASize; i++)
	{
		sumA += A[i];
	}
	for (i = 0; i<BSize; i++)
	{
		sumB += B[i];
	}
	if (sumA == sumB)
	{
		ans[0] = A[0];
		ans[1] = A[0];
		free(ans);
		return ans;
	}
	chaAver = (sumB - sumA) / 2;
	for (i = 0; i<ASize; i++)
	{
		for (int j = 0; j<BSize; j++)
		{
			if (B[j] == A[i] + chaAver)
			{
				ans[0] = A[i];
				ans[1] = B[j];
				return ans;
			}
		}
	}
	free(ans);
	return ans;
}

int main()
{
	int A[] = { 1,1 };
	int B[] = { 2,2 };
	int sz_A = sizeof(A) / sizeof(A[0]);
	int sz_B = sizeof(B) / sizeof(B[0]);
	int returnSize = 0;
	int * tpr = fairCandySwap(A, sz_A, B, sz_B, &returnSize);
	printf("%d", *(tpr));
	printf("%d", *(tpr + 1));
	system("pause");
	return 0;
}