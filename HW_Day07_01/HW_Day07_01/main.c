//使用递归与非递归实现求第n个斐波那契数
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int No_recursion(int n)
{
	int i = 0;
	int a = 1;
	int b = 1;
	int c = 0;
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		for (i = 3; i <= n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
}

int recursion(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return recursion(n - 1) + recursion(n - 2);
	}
}


int main()
{
	int n = 0;
	int test_a = 0;
	int test_b = 0;
	printf("请输入你想找的第几个斐波那契数:>\n");
	scanf("%d", &n);
	test_b = No_recursion(n);
	printf("%d\n", test_b);
	test_a = recursion(n);
	printf("%d\n", test_a);
	system("pause");
	return 0;
}