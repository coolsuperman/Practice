//在屏幕上输出以下图案：
//*
//***
//*****
//*******
//*********
//***********
//*************
//***********
//*********
//*******
//*****
//***
//*
//算法：利用for循环正向打印*；正向打印任务完成后进入if语句改变for循环条件使for循环继续进行，打印镜像；
//debug log：
//*******1.for循环的判断条件由一开始的"i>=num"修改为"i！=num"是为了方便直接修改判断部分；
#include<stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	int first = 1;
	int last = 15;
	int sign = 1;
	for (i = first; i != last; i+=2*sign)
	{
		for (j = 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
		if (i == 13)
		{
			first = 13;
			last = -1;
			sign = -1;
		}
	}
	system("pause");
	return 0;

}