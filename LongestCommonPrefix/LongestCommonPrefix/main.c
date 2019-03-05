//编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
	char* save_same = (char*)malloc(sizeof(char) * 2);
	int size = 2;
	int i = 0, j = 0;
	while (i<size)
	{
		save_same[i] = 0;
		i++;
	}
	for (j = 0;; j++)
	{
		if (*(strs[0] + j) != '\0')
		{
			save_same[j] = *(strs[0] + j);
			for (i = 0; i<strsSize; i++)
			{
				if (*(strs[i] + j) == '\0' || *(strs[i] + j) != save_same[j])
				{
					save_same[j] = 0;
					return save_same;
				}
			}
			realloc(save_same, ++size);
			save_same[size - 1] = 0;
		}
		else
		{
			return save_same;
		}
	}
}

char* stupid_longestCommonPrefix(char** strs, int strsSize)
{
	if (strsSize == 0)
	{
		return "";
	}
	int size = strlen(strs[0]) + 1;
	char* save_same = (char*)malloc(sizeof(char) * size);
	int i = 0, j = 0;
	while (i<size)
	{
		save_same[i] = 0;
		i++;
	}
	for (j = 0;; j++)
	{
		if (*(strs[0] + j) != '\0')
		{
			save_same[j] = *(strs[0] + j);
			for (i = 0; i<strsSize; i++)
			{
				if (*(strs[i] + j) == '\0' || *(strs[i] + j) != save_same[j])
				{
					save_same[j] = 0;
					return save_same;
				}
			}
			//realloc(save_same, ++size);
			//save_same[size - 1] = 0;
		}
		else
		{
			return save_same;
		}
	}
}


int main()
{
	char *strs[] = { "aflgh","flg","flg"};
	char* tpr = longestCommonPrefix(strs, 3);
	printf(tpr);
	free(tpr);
	system("pause");
	return 0;
}