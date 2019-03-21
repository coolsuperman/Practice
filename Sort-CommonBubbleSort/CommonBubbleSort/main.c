//模拟库函数qsort实现通用冒泡排序
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct Student
{
	char* name;
	double     tall;
	int        age;
};


void BubbleSort(int *dest, int sz)//只针对int型数据的一般冒泡排序
{
	for (int i = 0; i < sz-1; i++)//几趟
	{
		for (int j = 0; j < sz - i - 1; j++)//每趟判断几个元素
		{
			if (dest[j] > dest[j + 1])
			{
				int temp = dest[j];
				dest[j] = dest[j + 1];
				dest[j + 1] = temp;
			}
		}
	}
}

int compare_char(const void*elem1, const void*elem2)//需要使用者自己定义
{
	return *(char*)elem1 - *(char*)elem2;
}

int compare_int(const void*elem1,const void*elem2)//需要使用者自己定义
{
	return *(int*)elem1 - *(int*)elem2;
}

int compare_struct(const void*elem1, const void*elem2)//需要使用者自己定义
{ 
	return ((struct Student*)elem1)->age - ((struct Student*)elem2)->age;
}

void swap(char*elem1, char*elem2,unsigned int width)//按字节交换！这样可以不用判断到底是什么类型的数据
{
	assert(elem1 != NULL && elem2 != NULL);
	for (unsigned int i = 0; i < width; i++)
	{
		char temp = *(elem1 + i);
		*(elem1 + i) = *(elem2 + i);
		*(elem2 + i) = temp;
	}
}

void Common_BubbleSort(void*basic, int sz,unsigned int width, int(*cmp)(const void*elem1, const void*elem2))//大体框架相似于冒泡排序不同之处在于判断交换的条件
{
	for (int i = 0; i < sz - 1; i++)//几趟
	{
		for (int j = 0; j < sz - i - 1; j++)//每趟判断几个元素
		{
			if ((cmp((char*)basic+j*width,(char*)basic+(j+1)*width))>0)
			{
				swap((char*)basic + j*width, (char*)basic + (j + 1)*width,width);
			}
		}
	}
}


int main()//分别使用整形，字符，和结构体进行测试
{
	struct Student init[3] = { {"zhangsan",1.75,19},{"lisi",1.72,13},{"wangwu",1.65,18} };
	int arr_int[] = {2,4,3,6,5,1,8,7,9,6};
	char arr_char[] = { '2','4','3','6','5','1','8','7','9','6' };
	int sz_int = sizeof(arr_int) / sizeof(arr_int[0]);
	int sz_char = sizeof(arr_char) / sizeof(arr_char[0]);
	int sz_struct = sizeof(init) / sizeof(init[0]);
	unsigned int width_int = sizeof(int);
	unsigned int width_char = sizeof(char);
	unsigned int width_struct= sizeof(struct Student);
	//BubbleSort(arr, sz);
	Common_BubbleSort(arr_char, sz_char, width_char, compare_char);
	for (int i = 0; i < sz_char; i++)
	{
		printf("%c", *(arr_char + i));
	}
	printf("\n");
	system("pause");
	return 0;
}