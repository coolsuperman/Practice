//编写函数实现n^k,n!使用递归实现
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int JieCheng(int k)
{
	int value = 0;
	if (k < 2)
	{
		return 1;
	}
	else
	{
			return k*JieCheng(k-1);
	}
}
int CiFang(int n,int k)
{
	int value = 0;
	if (k < 2)
	{
		return n;
	}
	else
	{
		return n*CiFang(n,k - 1);
	}
}

int main()
{
	int value = 0;
	int k= 0;
	int n = 0;
	printf("请输入n值：>\n");
	scanf("%d", &n);
	printf("请输入k值：>\n");
	scanf("%d", &k);
	value = CiFang(n,k);
	printf("%d\n",value);
	system("pause");
	return 0;
}
