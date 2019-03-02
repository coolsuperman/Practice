//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。说明：本题中，我们将空字符串定义为有效的回文串。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define true 1
#define false 0

int isPalindrome(char* s)
{
	int len = 0;
	while (*(s + len))
	{
		len++;
	}
	char* back = s + len - 1;
	char* start = s;
	while (start<back)
	{
		while ((start<back) && ((*start<'0') || (*start>'9' && *start<'A') || (*start>'Z'&&*start<'a') || (*start>'z')))
		{
			start++;
		}
		while ((start<back) && ((*back<'0') || (*back>'9' && *back<'A') || (*back>'Z'&&*back<'a') || (*back>'z')))
		{
			back--;
		}
		if ((*start != *back) && (((*start>='0'&&*start<='9') || (*back>='0'&&*back<='9')) || ((*start + 32 != *back) && (*start - 32 != *back))))
		{
			return false;
		}
		start++;
		back--;
	}
	return true;
}

int main()
{
	char s[] = "0P";
	printf("%d", isPalindrome( s));
	system("pause");
	return 0;
}