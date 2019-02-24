//模拟实现strcpy和strcat；
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>

char* my_strcpy(const char*scr, char*dest)
{
	char*dest_start = dest;
	assert(scr != NULL && dest != NULL);
	while ((*dest++ = *scr++) != '\0')
	{
		;
	}
	return dest_start;
}

char* my_strcat(const char*scr, char*dest)
{
	char*dest_start = dest;
	assert(scr != NULL && dest != NULL);
	while (*dest != '\0')
	{
		dest++;
	}
	while ((*dest++ = *scr++) != '\0')
	{
		;
	}
	return dest_start;
}

int main()
{
	char arr[] = "abcdefg";
	char new[80] = { 0 };
	char* tpr =my_strcpy(arr, new);
	char* tpr2 = my_strcat(arr, new);
	for (int i = 0; i < sizeof(new) / sizeof(new[0]); i++)
	{
		printf("%c", tpr2[i]);
	}
	system("pause");
	return 0;
}