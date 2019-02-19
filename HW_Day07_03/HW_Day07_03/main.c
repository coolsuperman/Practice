//写一个递归函数DigitSum()，输入一个非负整数，返回组成他的数字之和；
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int DigitSum(int num)
{
	int temp;
	if (num < 10)
	{
		return num;
	}
	else
	{
		temp = num %10;
		return  temp+DigitSum(num / 10);
	}
}

int main()
{
	int num = 0;
	int sum = 0;
	printf("输入你想拆解的数：\n");
	scanf("%d", &num);
	sum = DigitSum(num);
	printf("%d\n", sum);
	system("pause");
	return 0;
}