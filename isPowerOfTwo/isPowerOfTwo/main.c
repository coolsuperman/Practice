//给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int isPowerOfTwo(int n)
{
	if (n>0)
	{
		return !(n&(n - 1));
	}
	return 0;
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	if (isPowerOfTwo(num))
	printf("是二的幂次方\n");
	else
		printf("不是2的幂次方\n");
	system("pause");
	return 0;
}