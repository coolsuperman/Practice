//假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。
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