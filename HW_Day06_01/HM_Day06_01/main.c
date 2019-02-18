#define _CRT_SECURE_NO_WARNINGS 1

//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己制定；
#include <stdio.h>
#include"printf_CFB.h"

int main()
{
	int row = 0;
	printf("请输入你所想打印的乘法表大小：\n");
	scanf("%d", &row);
	printf_CFB(row);
	system("pause");
	return 0;
}