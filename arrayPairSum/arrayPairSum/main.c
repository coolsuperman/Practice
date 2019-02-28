//给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int arrayPairSum_QuickSort(int* nums, int numsSize)
{
	int i = 0, j = 0, flag = 0, result = 0;
	for (i = 1; i<numsSize ; i++)
	{
		flag = nums[i];
		j = i - 1;
		while (j >= 0 && nums[j]>flag)
		{
			nums[j + 1] = nums[j];
			j--;
		}
	}
	nums[j+1] = flag;
	for (i = 0; i<numsSize; i += 2)
	{
		result += nums[i];
	}
	return result;
}

int arrayPairSum_bobbleSort(int* nums, int numsSize)
{
	int i = 0, j = 0, temp = 0, result = 0;
	for (i = 0; i<numsSize - 1; i++)
	{
		for (j = 0; j<numsSize - i - 1; j++)
		{
			if (nums[j]>nums[j + 1])
			{
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
	for (i = 0; i<numsSize; i += 2)
	{
		result += nums[i];
	}
	return result;
}

int main()
{
	int arr[] = { 1,4,3,2 };
	printf("%d", arrayPairSum_QuickSort(arr, 4));
	system("pause");
	return 0;
}