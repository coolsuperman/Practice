//������A������������B�����ݽ��н������������������һ����
//�㷨��ʹ���Լ���strcpy�����������м�����ʵ���������ݼ�Ľ���;
//debug log��
//*****1.��֤strlen����ͨ��������Ԫ�ص�ַ�ں����ڲ�����������Ԫ�ؽ��м��㣡�ҳ��Ƚ��������"\0"������sizeof�����ʲ�ͬ��;
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//#include<string.h>

void strcpy_s(char*arr1,char*arr2);

int main()
{
	char arr1[10] = { 0 };
	char arr2[10] = { 0 };
	char temp[10] = { 0 };
	strcpy_s(arr1, arr2);
	printf("arr1:>");
	scanf("%s", arr1);
	printf("\narr2:>");
	scanf("%s", arr2);
	strcpy_s(temp, arr1);
	strcpy_s(arr1, arr2);
	strcpy_s(arr2, temp);
	printf("\narr1:%s\n", arr1);
	printf("\narr2:%s\n", arr2);
	system("pause");
	return 0;
}

void  strcpy_s(char*arr1,char*arr2)
{
	int i = 0;
	int sz1 = strlen(arr1);
	int sz2 = strlen(arr2);
	int sz = sz1 > sz2 ? sz1 : sz2;
	//printf("%d", sz);
	for (i = 0; i < sz; i++)
	{
		arr1[i] = arr2[i];
	}
}