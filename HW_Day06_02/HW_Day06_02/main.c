#define _CRT_SECURE_NO_WARNINGS 1
//ʵ���������Ľ���
//˼·��ͨ�����������������Ĵ���ĵ�ַ��������ʵ�����Ľ�����
//ע���β�ֻ��ʵ�ε�һ����ʱ�������޷�ֱ�Ӹı�ʵ�ε�ֵ��������ý�����ַ�����У�

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
	printf("������a>");
	scanf("%d", &a);
	printf("������b>");
	scanf("%d", &b);
	exchange(&a, &b);
	printf("a=%d,b=%d\n", a, b);
	system("pause");
	return 0;
}
