//дһ���ݹ麯��DigitSum()������һ���Ǹ����������������������֮�ͣ�
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int DigitSum(int num)
{
	int temp;
	if (num < 10)
	{
		return num;
	}
	else
	{
		temp = num %10;
		return  temp+DigitSum(num / 10);
	}
}

int main()
{
	int num = 0;
	int sum = 0;
	printf("���������������\n");
	scanf("%d", &num);
	sum = DigitSum(num);
	printf("%d\n", sum);
	system("pause");
	return 0;
}