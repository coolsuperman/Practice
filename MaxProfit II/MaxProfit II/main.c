//����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸����һ���㷨�����������ܻ�ȡ�������������Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ��
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