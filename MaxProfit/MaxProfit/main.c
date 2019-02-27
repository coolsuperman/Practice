//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
//注意你不能在买入股票前卖出股票。
//思路：遍历一遍数组，每次更新买入最低的价格，然后每次用当前值减去最低买入价格，用来更新最大利润，最后得到的必定是最大利润；
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int maxProfit(int* prices, int pricesSize) 
{
	int min_in = 0x7FFFFFFF, realmax = 0;
	for (int i = 0; i < pricesSize; i++)
	{
		min_in = min_in<prices[i] ? min_in : prices[i];
		realmax = realmax>prices[i] - min_in ? realmax : prices[i] - min_in;
	}
	return realmax>0 ? realmax : 0;
}

int my_Stupid_maxProfit(int* prices, int pricesSize)
{
	int i = 0, j = 0, max = 0;
	for (i = 0; i<pricesSize; i++)
	{
		for (j = i + 1; j<pricesSize; j++)
		{
			max = max>prices[j] - prices[i] ? max : prices[j] - prices[i];
		}
	}
	return max >= 0 ? max : 0;
}

int main()
{
	int arr[] = { 7,1,5,3,6,4 };
	int pricesSize = sizeof(arr) / sizeof(arr[0]);
	printf("%d", maxProfit(arr, pricesSize));
	system("pause");
	return 0;
}