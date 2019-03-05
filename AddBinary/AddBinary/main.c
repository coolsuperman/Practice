//给定两个二进制字符串，返回他们的和（用二进制表示）,输入为非空字符串且只包含数字 1 和 0。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

char* addBinary(char* a, char* b)
{
	int numa = 0, numb = 0;
	while (*(a + numa)) { numa++; }
	while (*(b + numb)) { numb++; }
	int max = 0, i = numa - 1, j = numb - 1, add = 0;
	max = numa>numb ? numa : numb;
	char* result = (char*)malloc(sizeof(char)*(max + 2));
	result[max + 1] = '\0';
	for (int n = max; n >= 0; j--, i--, n--)
	{
		int value = 0;
		if (i >= 0 || j >= 0)
		{
			if (i >= 0 && j >= 0)
			{
				value = a[i] - '0' + b[j] - '0' + add;
			}
			else if (i >= 0)
			{
				value = a[i] - '0' + add;
			}
			else if (j >= 0)
			{
				value = b[j] - '0' + add;
			}
		}
		else
		{
			value = add;
		}
		if (value >= 2)
		{
			add = 1;
			value -= 2;
		}
		else
		{
			add = 0;
		}
		result[n] = value + '0';
	}
	if (result[0] - '0' == 0)
	{
		result++;
	}
	return result;
}


int main()
{
	char a[] = "1010";
	char b[] = "1011";
	printf(addBinary( a, b));
	system("pause");
	return 0;
}