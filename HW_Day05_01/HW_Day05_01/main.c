// 实现猜数字游戏.
//思路：首先用switch case实现菜单的选择，在选择进入游戏后使用srand函数产生随机数，与玩家输入的数进行判断；
//Debug log:
//*****1.switch case语句中执行break跳出后还要在while里进行判断；
//*****2.srand若在game函数，每次game中的rand被调用都会使用一个新的seed值（time被重置）使得得到的随机数过于相近，将srand放在main中得到改善；
//注：rand函数的使用：首先需要给srand函数提供一个unsigned int类型的可变化seed（2byte取值范围0~65535），sand返回0~32767的随机值;我们选择抓取计算机的时钟;
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu();
void game();

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	menu();
	do
	{
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("游戏退出中...\n");
			break;
		default:
			printf("错误，请重新输入!\n");
			break;
		}
	} while (input != 2);
	
	system ("pause");
	return 0;
}

void menu()
{
	printf("******************\n");
	printf("******1.开始******\n");
	printf("******2.退出******\n");
	printf("******************\n");
}

void game()
{
	int i= 1;
	int input = 0;
	i = rand() % 100;
	printf("快猜猜是多少？\n:>");
	for (; i != input;)
	{
		scanf("%d", &input);
		if (i > input)
		{
			printf("猜小了！\n:>");
		}
		else if (i < input)
		{
			printf("猜大了！\n:>");
		}
	}
	printf("恭喜你，猜中了!\n");
	//printf("%d", i);
}
