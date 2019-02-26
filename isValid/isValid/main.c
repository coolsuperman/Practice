//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。有效字符串需满足：左括号必须用相同类型的右括号闭合。左括号必须以正确的顺序闭合。注意空字符串可被认为是有效字符串。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int isValid(char* s)
{
	int len = 0;
	while (*(s + len)) { len++; }
	char* ptr = (char*)malloc((len / 2) + 2);
	memset(ptr, 0, (len / 2) + 2);
	int i = 0, a = 0;
	for (i = 0; i<len; i++)
	{
		if ((*(s + i) == '(') || (*(s + i) == '{') || (*(s + i) == '['))
		{
			a++;
			*(ptr + a) = *(s + i);
		}
		else if ((*(s + i) == (*(ptr + a) + 1)) || (*(s + i) == (*(ptr + a) + 2)))
		{
			a--;
		}
		else
		{
			return 0;
		}
	}
	if (a)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	char a[] = "()";
	if (isValid(a))
	{
		printf("符合标准\n");
	}
	else
	{
		printf("No\n");
	}
	system("pause");
	return 0;
}