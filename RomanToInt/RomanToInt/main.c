//给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int romanToInt(char* s)
{
	int sum = 0;
	while (*s)
	{
		if (*s == 'I')
		{
			if (*(s + 1) == 'V')
			{
				sum += 4;
				s += 2;
			}
			else if (*(s + 1) == 'X')
			{
				sum += 9;
				s += 2;
			}
			else
			{
				sum += 1;
				s++;
			}
		}
		else if (*s == 'V')
		{
			sum += 5;
			s++;
		}
		else if (*s == 'X')
		{
			if (*(s + 1) == 'L')
			{
				sum += 40;
				s += 2;
			}
			else if (*(s + 1) == 'C')
			{
				sum += 90;
				s += 2;
			}
			else
			{
				sum += 10;
				s++;
			}
		}
		else if (*s == 'L')
		{
			sum += 50;
			s++;
		}
		else if (*s == 'C')
		{
			if (*(s + 1) == 'D')
			{
				sum += 400;
				s += 2;
			}
			else if (*(s + 1) == 'M')
			{
				sum += 900;
				s += 2;
			}
			else
			{
				sum += 100;
				s++;
			}
		}
		else if (*s == 'D')
		{
			sum += 500;
			s++;
		}
		else
		{
			sum += 1000;
			s++;
		}
	}
	return sum;
}

int main()
{
	char s[] = "MCMXCIV";
	printf("%d", romanToInt(s));
	system("pause");
	return 0;
}