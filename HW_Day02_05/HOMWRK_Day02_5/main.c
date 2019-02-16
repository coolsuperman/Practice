//求两个数的最大公约数、最小公倍数。
//算法：最大公约数必然小于两个数中最小的，且可被两个数同时整除；最小公倍数必然大于两个数中最小的，且可同时整除以两个数；
#include<stdio.h>

void Max_GYS(int a, int b);
void Min_GBS(int a, int b);

int main()
{
	int a = 0;
	int b = 0;
	scanf_s("%d %d",&a,&b);
	Max_GYS(a, b);
	Min_GBS(a, b);
	system("pause");
	return 0;
}

void Max_GYS(int a, int b)
{
	int i = 0;
	if (a < b)
	{
		i = a;
	}
	else
	{
		i = b;
	}
	for (;i>=1; i--)
	{
		if (a%i == 0 && b%i == 0)
		{
			printf("最大公约数是%d\n", i);
			break;
		}
	}

}
void Min_GBS(int a, int b)
{
	int i = 0;
	if (a < b)
	{
		i = a;
	}
	else
	{
		i = b;
	}
	for (; ; i++)
	{
		if (i%a == 0 && i%b == 0)
		{
			printf("最小公倍数是%d\n", i);
			break;
		}
	}

}
