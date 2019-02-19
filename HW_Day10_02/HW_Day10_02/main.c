//获取一个数的二进制数列中的所有偶数位和奇数位；分别输出二进制数列；
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>

enum number
{
	even ,//想要奇数位；
	odd //想要偶数位；
};

int* get_bit(const  int value,int* arr,int want)//增加const：防止在运算过程中改变了value的值；
{
	assert(arr !=NULL);//防止存放信息的数组是一个空指针；
	int *ret = arr;
	int i = 0;
	for (i = want; i < 32; i+=2)
	{
		*(arr++) = (value >> i) % 2;
	}
	return ret;
}

int main()
{
	int arr[16] = { 0 };
	int value = 0;
	int* tpr = arr;
	int i = 0;
	printf("请输入你期望的数:>\n");
	scanf("%d", &value);
    get_bit(value, arr, even);
	printf("\n偶数列：\n");
	for (i = 0; i < 16; i++)
	{
		if (i % 4 == 0)
		{
			printf(" ");//每四位空格方便看得清楚；
		}
		printf("%d", *(tpr++));
	}
	tpr = get_bit(value, arr, odd);
	printf("\n奇数列：\n");
	for (i = 0; i < 16; i++)
	{
		if (i % 4 == 0)
		{
			printf(" ");
		}
		printf("%d", *(tpr++));
	}
	printf("\n");
	system("pause");
	return 0;
}