//���������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ�������-1���۰���ң���
//˼·���ֳƶ��ֲ��ҷ�����Ϊ���������У����Կ����ȵõ����鳤�������˵��±�ֱ�ӵõ��м�ֵ��Ŀ�����Ƚϴ�С��Ȼ����С��Χ�Դ�����ֱ������Ŀ������δ�ҵ�Ŀ����,
//�����Сʱ�临�Ӷȣ�
//Debug log��
//*****1.��ʹ��mid =  (right - left) / 2;���ʱ�������bin_search����ʱ�������滻Ϊmid = left + (right - left) / 2;��ʵ�ֹ��ܣ�
//*****ԭ���߼����󣬵�����whileѭ����arr[mid]���ʵ�������ķǷ���ַ���������;


#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int bin_search(int*arr[],int x,int sz);


int main()
{
	int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int x = 0;
	int sign = 0;
	int sz = sizeof arr / sizeof arr[0];
	printf("����������Ҫ���ҵ���(1~15)��>");
	scanf("%d", &x);
	sign = bin_search(arr, x, sz);
	printf("\nҪ���ҵ����������е��±�Ϊ��%d\n", sign);
	system("pause");
	return 0;
}

int bin_search(int* arr[], int x, int sz)
{
	int left = 0;
	int right = sz - 1;
	int mid = 0;
	while (left <= right)
	{
		//mid =  (right - left) / 2;
		mid = left + (right - left) / 2;
		if (x > arr[mid])
		{
			left = mid + 1;
		}
		else if (x < arr[mid])
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}