//����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Stupid_moveZeroes(int* nums, int numsSize)
{
	int* nums_copy = (int*)malloc(sizeof(int)*numsSize);
	for (int k = 0; k<numsSize; k++)
	{
		*(nums_copy + k) = 0;
	}
	int j = 0;
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] != 0)
		{
			nums_copy[j++] = nums[i];
		}
	}
	for (int i = 0; i<numsSize; i++)
	{
		nums[i] = nums_copy[i];
	}
}

void moveZeroes(int* nums, int numsSize)
{
	int j = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] != 0)
		{
			nums[j++] = nums[i];
		}
	}
	while (j < numsSize)
	{
		nums[j++] = 0;
	}
}

int main()
{
	int nums[] = { 0,1,2,0,4 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	moveZeroes(nums, numsSize);
	for (int i = 0; i < numsSize; i++)
	{
		printf("%d", *(nums + i));
	}
	printf("\n");
	system("pause");
	return 0;
}