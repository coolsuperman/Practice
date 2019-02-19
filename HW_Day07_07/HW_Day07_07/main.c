//递归方式实现打印一个整数的每一位
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void print(int num)
{
	int apart = 0;
	if (num < 10)
	{
		printf("%d\n", num);
	}
	else
	{
		apart = num % 10;
		printf("%d\n", apart);
		print(num / 10);
	}
}

int main()
{
	int num = 0;
	printf("请输入你想要分解的数字：\n");
	scanf("%d", &num);
	print(num);
	system("pause");
	return 0;
}