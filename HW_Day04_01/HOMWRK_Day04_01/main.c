//����Ļ���������ͼ����
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
//�㷨������forѭ�������ӡ*�������ӡ������ɺ����if���ı�forѭ������ʹforѭ���������У���ӡ����
//debug log��
//*******1.forѭ�����ж�������һ��ʼ��"i>=num"�޸�Ϊ"i��=num"��Ϊ�˷���ֱ���޸��жϲ��֣�
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