//����һ����СΪ n �����飬�ҵ����е�������������ָ�������г��ִ������� ? n/2 ? ��Ԫ�ء�
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
	printf("\n������:%d\n", majorityElement( arr,10));
	system("pause");
	return 0;
}