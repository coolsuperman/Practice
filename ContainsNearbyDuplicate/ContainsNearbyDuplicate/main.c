//给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define true 1
#define false 0

int containsNearbyDuplicate(int* nums, int numsSize, int k)
{
	for (int i = 0; i<numsSize; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if ((i + j)<numsSize)
			{
				if (nums[i] == nums[i + j])
				{
					return true;
				}
			}
		}
	}
	return  false;
}

int main()
{
	int arr[] = {1,0,1,1};
	int K = 1;
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("%d", containsNearbyDuplicate(arr, sz, K));
	system("pause");
	return 0;
}