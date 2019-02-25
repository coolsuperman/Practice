//给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ? n/2 ? 的元素。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int majorityElement(int* nums, int numsSize)
{
	int count = 1;
	int judge = *nums;
	for (int i = 1; i<numsSize; i++)
	{
		if (judge == nums[i])
		{
			count++;
		}
		else
		{
			count--;
			if (count == 0)
			{
				judge = nums[i];
				count = 1;
			}
		}
	}
	return judge;
}

int main()
{
	int arr[] = {0,1,3,5,3,0,0,0,3,0};
	printf("\n众数是:%d\n", majorityElement( arr,10));
	system("pause");
	return 0;
}