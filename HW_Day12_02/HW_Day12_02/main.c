//��ʹ��(a+b)/2���ַ�ʽ��������ƽ��ֵ
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int add1(int a, int b)
{
	return a - (a - b)/2;
}

int add2(int a, int b)
{
	return (a + b) >> 1;
}

//int add3(int a, int b)
//{
//	int count =0;
//	int ret = a + b;
//	while (ret-=2)
//	{
//		count++;
//	}
//	return count+1;
//}//ֻ������ֵ

int main()
{
	int a = 0, b = 0;
	printf("����������Ҫ��ֵ:>\n");
	scanf("%d%d", &a, &b);
	printf("%d\n", add1(a, b));
	printf("%d\n", add2(a, b));
	//printf("%d\n", add3(a, b));
	system("pause");
	return 0;
}