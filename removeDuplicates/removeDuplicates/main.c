//����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ���Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
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