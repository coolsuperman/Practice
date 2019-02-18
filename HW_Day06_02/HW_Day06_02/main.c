#define _CRT_SECURE_NO_WARNINGS 1
//实现两个数的交换
//思路：通过像函数传递两个数的储存的地址并交换来实现数的交换；
//注：形参只是实参的一份临时拷贝，无法直接改变实参的值，建议采用交换地址来进行；

#include<stdio.h>

void exchange(int*a, int*b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}


int main()
{
	int a = 0;
	int b = 0;
	printf("请输入a>");
	scanf("%d", &a);
	printf("请输入b>");
	scanf("%d", &b);
	exchange(&a, &b);
	printf("a=%d,b=%d\n", a, b);
	system("pause");
	return 0;
}
