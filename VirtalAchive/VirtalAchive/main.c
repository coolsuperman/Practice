//模拟实现:strcpy,strcat,strstr,strchr,strcmp,memcpy,memove
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

int strlen_NoReverse(const char*arr)
{
	int count = 0;
	assert(arr);
	while (*arr++ != '\0')
	{
		count++;
	}
	return count;
}

int strlen_Reverse(const char*arr)
{
	assert(arr);
	if (*arr == '\0')
		return 0;
	else
		return 1 + strlen_Reverse(arr + 1);
}

char* my_strcpy(char*dest, const char*src)//目标空间必须足够，目标和源必须都不为Null
{
	char*ret = dest;
	assert(dest&&src);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

char* my_strcat(char*dest, const char*src)//目标空间必须足够，目标和源必须都不为Null
{
    char*ret = dest;
	assert(dest&&src);
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

char* my_strstr(const char*dest,const char*src)
{
	assert(dest&&src);
	const char*check_start = dest;
	const char*src_back = src;
	while (*dest != '\0')
	{
		dest = check_start;
		while (*dest&&*src && *dest == *src)//出现同步开始判断
		{
			dest++;
			src++;
		}
		if (*src == '\0')
		{
			return (char*)check_start;
		}
		src = src_back;
		check_start++;
	}
	return NULL;
}

char* my_strchr(const char*dest, int cha)
{
	assert(dest);
	while (*dest)
	{
		if (*dest == cha)
		{
			return (char*)dest;
		}
		dest++;
	}
	return NULL;
}

int my_strcmp(const char* arr1, const char*arr2)
{
	assert(arr1&&arr2);
	while (*arr1==*arr2)
	{
			arr1++;
			arr2++;
	}
	return *arr1 - *arr2;
}

void* my_memcpy(void*dest,const void*src,unsigned int byte)
{
	assert(dest&&src);
	void*ret = dest;
	while (byte--)
	{
		*((char*)dest)++ = *((char*)src)++;
	}
	return ret;
}

void* my_memmov(void*dest, const void*src, unsigned int byte)
{
	assert(dest&&src);
	void*ret = dest;
	if (src > dest)//采用正序法不会丢失数据；
	{
		while (byte--)
		{
			*((char*)dest)++ = *((char*)src)++;
		}
	}
	if (src < dest)//采用倒序法不会丢失数据；
	{
		while (byte--)
		{
			*(((char*)dest)+byte) = *(((char*)src)+byte);
		}
	}
	return ret;
}

int main()
{
	char arr2[20] = "aaaaa";
	char arr[] = "bba";
	int   arr3[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int   arr4[] = { 1,2,3,4,5 };
	//printf("%d", strlen_Reverse(arr2));//test for strlen_Reverse;
	//printf("%d", strlen_NoReverse(arr2));//test for strlen_NoReverse;
	//my_memmov(arr3 + 3, arr3, 16);//test for my_memmov;
	//my_memcpy(arr3+3 ,arr3, 16);//test for my_memcpy;
	//printf("%d", my_strcmp(arr2, arr));//test for my_strcmp;
	//printf("%s", my_strcat(arr2, arr));//test for my_strcat/my_strcpy;
	if (my_strstr(arr2, arr))// test for my_strstr;
	{
		printf("%s", my_strstr(arr2, arr));
	}
	else
	{
		printf("没找着子序列\n");
	}
	//printf("%s", my_strchr(arr2, 'b'));//test for my_strchr;
	system("pause");
	return 0;
}