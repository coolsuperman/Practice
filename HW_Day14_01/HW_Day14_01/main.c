//ʵ��һ����������������ת�ַ����е�K���ַ���ABCD����һ���ַ��õ�BCDA��ABCD���������ַ��õ�CDAB��
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

char * Levorotation(char*arr, int num,int sz)
{
	int i = 0;
	char*temp = (char*)malloc(num*sizeof(char));
	for ( i = 0; i < num; i++)
	{
		*(temp + i) = *(arr + i);
	}
	for (i = 0; i < sz-num; i++)
	{
		*(arr + i) = *(arr + num + i);
	}
	for (i = 0; i < num; i++)
	{
		*(arr +sz-num+ i) = *(temp++);
	}
	return arr;
}

int main()
{
	char arr[] = "ABCDEFG";
	int sz = sizeof(arr) / sizeof(arr[0])-1;
	int i = 0;
	int num = 0;
	do
	{
		printf("����������Ҫ�����ĸ���(0~%d):>",sz);
		scanf("%d", &num);
	} while (num < 0 || num > sz);
	char* tpr = Levorotation(arr, num, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%c", *(tpr+ i));
	}
	system("pause");
	return 0;
}