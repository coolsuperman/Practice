//模拟实现strncpy.strncat.strncmp
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

char* my_strcnpy(char*dest ,const char*src,unsigned int num)//注意:num大于src里的元素个数自动补0；
{
	char* ret= dest;
	assert(dest&&src);
	while (num--)
	{
		if (*src != '\0')
		{
			*dest++ = *src++;
		}
		else
		{
			*dest++ = '\0';
		}
	}
	return ret;
}

char* my_strncat(char* dest,const char* src, unsigned int num)//注意：num大于src里的元素个数并不补零；
{
	assert(dest&&src);
	char* ret = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while ((*dest++ = *src++) && (--num))//这里--num是因为在num=0时前面的dest和Scr还要再判断赋值一次;nun--会多运行一次
	{
		;
	}
	return ret;
}

int my_strncmp(const char* arr1,const char*arr2,unsigned int num)
{
	assert(arr1&&arr2);
	while (*arr1==*arr2&&--num)
	{
			arr1++;
			arr2++;
	}
	return *arr1 - *arr2;
}

int main()
{
  char arr1[20] = "abcdxxxxxxx";
  char arr2[] = "abcdefg";
  printf("%d", my_strncmp(arr1, arr2, 4));//test for my_strncmp;
  //printf("%s", my_strncat(arr1, arr2, 1));//test for my_strncat;
  //printf("%s", my_strcnpy(arr1, arr2, 5));//test for my_strncpy;
  system("pause");
  return 0;
}