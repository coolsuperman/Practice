//�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n������Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void merge(int* nums1, int m, int* nums2, int n)
{
	int box = m + n - 1, i = n - 1, j = m - 1;
	while (i >= 0 && j >= 0)
	{
		nums1[box--] = nums1[j]>nums2[i] ? nums1[j--] : nums2[i--];
	}
	while (i >= 0)
	{
		nums1[box--] = nums2[i--];
	}
}

void merge2(int* nums1, int m, int* nums2, int n)
{
	int i = 0;
	for (i = m; i<m + n; i++)
	{
		nums1[i] = nums2[i - m];
	}
	for (i = 0; i<m + n - 1; i++)
	{
		for (int j = 0; j<m + n - i - 1; j++)
			if (nums1[j]>nums1[j + 1])
			{
				int temp = nums1[j + 1];
				nums1[j + 1] = nums1[j];
				nums1[j] = temp;
			}
	}
}

int main()
{
	int arr1[] = { 1,3,5,7,9,10,0,0,0,0 };
	int arr2[] = {2,4,6,8};
	int m = sizeof(arr1) / sizeof(arr1[0]), n = sizeof(arr2) / sizeof(arr2[0]);
	merge2(arr1, m, arr2, n);
	system("pause");
	return 0;
}