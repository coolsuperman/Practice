//���Ͼ�����һ����ά���飬�����ÿ�д������ǵ����ġ�ÿ�д��ϵ����ǵ����ģ�������һ�������в���һ�������Ƿ���ڡ�
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
	printf("��������Ҫ���ҵ���:>\n");
	scanf("%d", &traget);
	int x = 3, y = 3;
	if (Y_Find(traget, Y_list,&x,&y))
		printf("�ҵ��ˣ�����:x=%d y=%d\n",x+1,y+1);
	else
		printf("û�ҵ�!\n");
	system("pause");
	return 0;
}