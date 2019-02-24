//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int maxSubArray(int* nums, int numsSize)
{
	int sum = 0, i;
	int res = INT_MIN;
	for (i = 0; i<numsSize; i++)
	{
		if (sum >= 0)
			sum += nums[i];
		else
			sum = nums[i];
		res = (sum>res) ? sum : res;
	}
	return res;
}

int stupid_maxSubArray(int* nums, int numsSize)
{
	int max_final = 0, max = 0, max_special = nums[0];
	int *nums_end = nums + numsSize - 1;
	if (numsSize == 1) { return *nums; }
	while (nums<nums_end)
	{
		max = 0;
		while ((*nums<0 || *(nums + 1) + *(nums)<0))
		{
			max_special = max_special>(*nums) ? max_special : (*nums);
			nums++;
			if (nums >= nums_end)
			{
				max_special = max_special>(*nums) ? max_special : (*nums);
				if (max_final == 0) { return max_special; }
				else break;
			}
		}
		//max_start = nums;
		while (nums<nums_end && (*(nums + 1) + *(nums) >= 0))
		{
			max += *(nums);
			nums++;
		}
		if (*nums >= 0)
		{
			if (nums >= nums_end && (*nums + *(nums - 1) < 0))
			{
				break;
			}
			max += *(nums);
		}
		max_final = max>max_final ? max : max_final;
	}

	return max_final;

}

int main()
{
	int arr[] = { -2,1,-3,4,-1,2,1,-5,4 };
	printf("%d",maxSubArray(arr, 9));
	system("pause");
	return 0;
}