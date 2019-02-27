//����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸���������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������
//ע���㲻���������Ʊǰ������Ʊ��
//˼·������һ�����飬ÿ�θ���������͵ļ۸�Ȼ��ÿ���õ�ǰֵ��ȥ�������۸�������������������õ��ıض����������
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