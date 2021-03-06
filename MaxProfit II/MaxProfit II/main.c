//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int maxProfit(int* prices, int pricesSize)
{
	int min = prices[0];
	int profit = 0;
	for (int i = 1; i<pricesSize; i++)
	{
		min = prices[i]<min ? prices[i] : min;
		if (prices[i]>prices[i - 1])
		{
			profit += prices[i] - prices[i - 1];
			min = prices[i];
		}
	}
	return profit;
}

int main()
{
	int arr[] = { 7,1,5,3,6,4};
	printf("%d", maxProfit(arr, 6));
	system("pause");
	return 0;
}