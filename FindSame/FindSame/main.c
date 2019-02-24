//如果一个数组中存在相同的元素，返回true，否则返回false；
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int  containsDuplicate(int* nums, int numsSize)
{
	int i = 0;
	if (numsSize>1)
	{
		for (i = 0; i<numsSize; i++)
		{
			for (int j = i + 1; j<numsSize; j++)
			{
				if (nums[i] == nums[j])
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int nums[] = { 10,9,10,5,2,6,8,7,1,3};
	printf("%d", containsDuplicate(nums, 10));
	system("pause");
	return 0;
}