//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int firstUniqChar(char* s)
{
	int alpha[26] = { 0 };
	int i = 0;
	for (i = 0; s[i]; i++)
	{
		alpha[s[i] - 'a']++;
	}
	for (i = 0; s[i]; i++)
	{
		if (alpha[s[i] - 'a'] == 1)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	char s[] = "cc";
	printf("%d", firstUniqChar(s));
	system("pause");
	return 0;
}