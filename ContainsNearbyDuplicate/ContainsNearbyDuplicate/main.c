//����һ�����������һ������ k���ж��������Ƿ����������ͬ������ i �� j��ʹ�� nums [i] = nums [j]������ i �� j �Ĳ�ľ���ֵ���Ϊ k��
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