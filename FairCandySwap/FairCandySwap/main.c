//爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 块糖的大小，B[j] 是鲍勃拥有的第 j 块糖的大小。因为他们是朋友，所以他们想交换一个糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。如果有多个答案，你可以返回其中任何一个。保证答案存在。
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