#define _CRT_SECURE_NO_WARNINGS 1

//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ��ƶ���
#include <stdio.h>
#include"printf_CFB.h"

int main()
{
	int row = 0;
	printf("�������������ӡ�ĳ˷����С��\n");
	scanf("%d", &row);
	printf_CFB(row);
	system("pause");
	return 0;
}