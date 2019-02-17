//将数组A的内容与数组B的内容进行交换（两个数组的内容一样大）
//算法：使用自己的strcpy函数，创建中间数组实现数组内容间的交换;
//debug log：
//*****1.验证strlen可以通过数组首元素地址在函数内部对整个数组元素进行计算！且长度结果不包含"\0"（这与sizeof的特质不同）;
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