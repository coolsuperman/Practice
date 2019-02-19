//递归和非递归分别实现Strlen函数
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int No_recursion(char arr[])
{
	int count = 0;
	while (*arr != '\0')
	{
			arr++;
			count++;
	}
	return count;
}

int recursion(char arr[])
{
	if (*(arr) != '\0')
	{
		return 1+(recursion(++arr)) ;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int result1 = 0;
	int result2 = 0;
	char arr[] = "abcdef";
	result1 = No_recursion(arr);
	printf("%d\n", result1);
	result2 = recursion(arr);
	printf("%d\n", result2);
	system("pause");
	return 0;
}