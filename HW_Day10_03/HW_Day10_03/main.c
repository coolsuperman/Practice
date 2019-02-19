//输出一个整数的每一位；
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void Digit_num(int value)
{
	if (value >= 10)
	{
		printf("\n%d", value % 10);
		Digit_num(value / 10);
	}
	else
	{
		printf("\n%d\n", value);
	}
}

int main()
{
	int num = 0;
	printf("请输入你想要拆解的数字:>\n");
	scanf("%d", &num);
	Digit_num(num);
	system("pause");
	return 0;
}