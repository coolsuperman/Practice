#define _CRT_SECURE_NO_WARNINGS 1
//设计一个函数判断一个数是不是素数；

#include <stdio.h>
#include <math.h>

int pf_Ss(int num)
{

	int j = 0;
	for (j = 1; j < sqrt(num, 2); j++)
	{
		int judge_ZC;
		judge_ZC = num%j;
		if (judge_ZC == 0)
		{
			return 1;
		}
	}
	return -1;
}


int main()
{
	int judge;
	int num;
	printf("Input the number:\n");
	scanf("%d", &num);
	judge = pf_Ss(num);
	if (judge == 1)
	{
		printf("是素数\n");
	}
	else
	{
		printf("不是素数\n");
	}
	system("pause");
	return 0;
}

