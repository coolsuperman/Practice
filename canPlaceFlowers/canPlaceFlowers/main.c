//��������һ���ܳ��Ļ�̳��һ���ֵؿ���ֲ�˻�����һ����ȴû�С����ǣ����ܲ�����ֲ�����ڵĵؿ��ϣ����ǻ�����ˮԴ�����߶�����ȥ������һ����̳����ʾΪһ���������0��1������0��ʾû��ֲ����1��ʾ��ֲ�˻�������һ���� n ���ܷ��ڲ�������ֲ�������������� n �仨�����򷵻�True�������򷵻�False��
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int canPlaceFlowers(int* flowerbed, int flowerbedSize, int n)
{
	int i = 0;
	if (flowerbedSize == 1)
	{
		if (n == 1)
		{
			return !flowerbed[0];
		}
		else
			return 1;
	}
	if (flowerbed[1] == 0 && flowerbed[0] == 0)
	{
		flowerbed[0] = 2;
		n--;
	}
	for (i = 1; i<flowerbedSize - 1; i++)
	{
		if (flowerbed[i] == 0)
		{
			if (flowerbed[i + 1] == 0 && flowerbed[i - 1] == flowerbed[i + 1])
			{
				flowerbed[i] = 2;
				n--;
			}
		}

	}
	if (flowerbed[flowerbedSize - 2] == 0 && flowerbed[flowerbedSize - 1] == 0)
	{
		n--;
	}
	if (!(n>0))
	{
		return 1;
	}
	return 0;
}

int main()
{
	int arr[] = { 0,0,1,0,0 };
	int n = 1;
	printf("%d", canPlaceFlowers(arr, 5,1));
	system("pause");
	return 0;
}