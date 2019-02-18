#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int Judge_RN(int year)
{
		int judge_1 = 0;
		int judge_2 = 0;
		if (year % 4 == 0)
		{
			judge_1 = 1;
		}
		if (year % 1000 != 0)
		{
			judge_2 = 1;
		}
		if (judge_1 == 1 && judge_2 == 1)
		{
			return 1;
		}
		else
		{
			return -1;
		}

}

int main()
{
	int year = 0;
	int result = 0;
	printf("Please type the year you want to judge:\n");
	scanf("%d", &year);
	result = Judge_RN(year);
	if (result == 1)
	{
		printf("\n是闰年\n");
	}
	else
	{
		printf("\n不是闰年\n");
	}
	system("pause");
	return 0;
}
