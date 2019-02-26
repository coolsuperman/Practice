//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
	int i = 0;
	for (int j = i + 1; j<numsSize; j++)
	{
		if (nums[j]!=nums[i])
		{
			i++;
			nums[i] = nums[j];
		}
	}
	return i + 1;
}

int my_removeDuplicates(int* nums, int numsSize)
{
	if (!numsSize)
	{
		return 0;
	}
	int* nums_flag = nums;
	int* nums_gocheck = nums;
	int *nums_end = nums + numsSize - 1;
	int i = 0;
	while (nums_gocheck <= nums_end)
	{
		while (nums_gocheck <= nums_end&&*(nums_flag + i) == *nums_gocheck)
		{
			nums_gocheck++;
		}
		if (nums_gocheck <= nums_end)
		{
			nums[++i] = *nums_gocheck;
		}
	}
	return i + 1;
}

int main()
{
	int nums[] = {0,0,1,1,5,5,5,6,6,6,7,7};
	int sz = sizeof(nums) / sizeof(nums[0]);
    my_removeDuplicates(nums, sz);
	for (int i = 0; i < sz ; i++)
	{
		printf("%d  ",nums[i]);
	}
	system("pause");
	return 0;
}