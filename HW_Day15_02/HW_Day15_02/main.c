//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水
//在我们看来两个空瓶换一瓶汽水也可以说，两个空瓶又是一块钱，20元钱喝完后我们卖了瓶子又获得了10元，10买了喝完后，我们又换了5元钱，据此我们就可以设计递归函数；
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int HowMany_recourse(int money,int signal)//递归算法
{
	if (signal == 2)
	{
		money += 1;
		signal = 0;
	}
	if (money <1)
	{
		return 0;
	}
	else
	{
		return money + HowMany(money / 2,money%2+signal);
	}
}

int HowMany(int money)//非递归
{
	int total = money;
	int empty = money;
	while (empty > 1)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	return total;
}

int main()
{
	int num = 0;
	printf("你有多少钱？\n");
	scanf("%d", &num);
	printf("可以喝%d瓶汽水\n", HowMany_recourse(num,0));
	printf("可以喝%d瓶汽水\n", HowMany(num));
	printf("可以喝%d瓶汽水\n",2*num-1);//递推式
	system("pause");
	return 0;
}