//编写程序数一下1to100的所有整数中出现了多少次数字9
//算法：含有9的数字均可加1后被10整除，而其余数字均不存在此特性。
#include<stdio.h>

int main()
{
	int count = 0;
	int i = 0;
	int flag = 0;
	for (i = 1; i <= 100; i++)
	{
		flag = 0;
		if ((i + 1) % 10 == 0)
		{
			flag = 1;
		}
		if (flag == 1)
		{
			count++;
		}
	}
	printf("出现9次数：%d\n", count);
	system("pause");
	return 0;
}