//����һ���Ѱ����������� ���������飬�ҵ�������ʹ���������֮�͵���Ŀ������ index1 �� index2������ index1 ����С�� index2�������±��1��ʼ��
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
	int another = 0;
	int* tpr = (int*)malloc(sizeof(int) * 2);
	*returnSize = 2;
	int start, end;
	{
		for (int i = 0; i<numbersSize; i++)
		{
			another = target - numbers[i];
			if (another >= numbers[i])
			{
				start = i + 1;
				end = numbersSize - 1;
				while (start <= end)
				{
					int mid = (start + end) / 2;
					if (numbers[mid] == another)
					{
						tpr[0] = i + 1;
						tpr[1] = mid + 1;
						return tpr;
					}
					else if (numbers[mid]<another)
					{
						start = mid + 1;
					}
					else
					{
						end = mid - 1;
					}
				}
			}
		}
	}
	return tpr;
}

int main()
{
	int nums[] = { 2,7,11,15};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int target = 9;
	int returnSize = 0;
	int* hehe = twoSum(nums, numsSize, target, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d", *(hehe+i));
	}
	system("pause");
	return 0;
}