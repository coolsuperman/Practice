//给定一个未经排序的整数数组，找到最长且连续的的递增序列。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int findLengthOfLCIS(int* nums, int numsSize)
{
	if (numsSize == 0)
	{
		return 0;
	}
	int max = 1, start = 0;
	for (int i = 1; i<numsSize; i++)
	{
		if (nums[i] - nums[i - 1]>0)
		{
			int judge = i - start + 1;
			max = max>judge ? max : judge;
		}
		else
		{
			start = i;
		}
	}
	return max;
}

int main()
{
	int nums[] = { 1,3,5,4,7 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	printf("%d", findLengthOfLCIS(nums, numsSize));
	system("pause");
	return 0;
}