//两个int (32bit)整数m和n的二进制表达，有多少个(bit)不同？
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int num_cmp(const int num1,const int num2)
{
	int i = 32;
	int count = 0;
	while (i--)
	{
		count += ((num1 >> i) % 2 != (num2 >> i) % 2);
	}
	return count;
}

int main()
{
	int num1 = 0;
	int num2 = 0;
	int recover = 0;
	printf("Please type two numbers that you wnant to compare:>\n");
	scanf("%d%d", &num1, &num2);
	recover = num_cmp(num1, num2);
	printf("这两个值的二进制表达中有%d个bit不同\n",recover);
	system("pause");
	return 0;
}