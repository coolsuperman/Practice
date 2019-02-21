//杨氏矩阵，有一个二维数组，数组的每行从左到右是递增的。每列从上到下是递增的，在这样一个数组中查找一个数组是否存在。
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int Y_Find(int traget,int(*ptr)[4],int*px,int *py)
{
	int x = 0;
	int y = *py - 1;
	while (x < 3 || y >= 0)
	{
		if ((*(*ptr + x) + y) < traget)
		{
			x++;
		}
		else if ((*(*ptr + x) + y) > traget)
		{
			y--;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int Y_list[3][3] = { 1,2,3   ,2,3,4    ,3,4,5};
	int traget = 0;
	printf("请输入需要查找的数:>\n");
	scanf("%d", &traget);
	int x = 3, y = 3;
	if (Y_Find(traget, Y_list,&x,&y))
		printf("找到了！坐标:x=%d y=%d\n",x+1,y+1);
	else
		printf("没找到!\n");
	system("pause");
	return 0;
}