//数组的每个索引做为一个阶梯，第 i个阶梯对应着一个非负数的体力花费值 cost[i](索引从0开始)。每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。
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
	printf("最小的花费是:%d", minCostClimbingStairs(cost, costSize));
	system("pause");
	return 0;
}