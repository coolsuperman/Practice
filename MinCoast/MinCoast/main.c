//�����ÿ��������Ϊһ�����ݣ��� i�����ݶ�Ӧ��һ���Ǹ�������������ֵ cost[i](������0��ʼ)��ÿ��������һ�������㶼Ҫ���Ѷ�Ӧ����������ֵ��Ȼ�������ѡ�������һ�����ݻ������������ݡ�����Ҫ�ҵ��ﵽ¥�㶥������ͻ��ѡ��ڿ�ʼʱ�������ѡ�������Ϊ 0 �� 1 ��Ԫ����Ϊ��ʼ���ݡ�
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int minCostClimbingStairs(int* cost, int costSize)
{
	if (costSize<2)
	{
		return 0;
	}
	int* CostCount = (int*)malloc(sizeof(int)*costSize);
	CostCount[0] = cost[0];
	CostCount[1] = cost[1];
	for (int i = 2; i<costSize; i++)
	{
		CostCount[i] = CostCount[i - 1]<CostCount[i - 2] ? CostCount[i - 1] + cost[i] : CostCount[i - 2] + cost[i];
	}
	return CostCount[costSize - 1]<CostCount[costSize - 2] ? CostCount[costSize - 1] : CostCount[costSize - 2];
}

int main()
{
	int cost[] = { 10,15,20 };
	int costSize = sizeof(cost) / sizeof(cost[0]);
	printf("��С�Ļ�����:%d", minCostClimbingStairs(cost, costSize));
	system("pause");
	return 0;
}