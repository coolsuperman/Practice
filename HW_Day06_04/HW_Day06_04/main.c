#define _CRT_SECURE_NO_WARNINGS 1
//创建一个数组，实现init初始化empty（）清空数组，实现reverse（）函数完成数组元素的逆置；
//注：malloc函数是向堆申请空间的函数void *malloc(size_t size);申请到的是连续的未被初始化的空间；

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void menu()
{
	printf("*********************\n");
	printf("***1,初始化数组*****\n");
	printf("***2,清空数组*******\n");
	printf("***3,数组元素逆置**\n");
	printf("***4,退出程序*******\n");
	printf("*********************\n");
}
void init(int*arr, int n)
{
	int i = 0;
	printf("请输入初始化数组元素：>\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("初始化成功！\n");
	for (i = 0; i <n; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}

void CLR(int*arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
	printf("数组已清空！\n");
	for (i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}

void reverse(int*arr, int n)
{
	int right = n-1;
	int left = 0;
	int i = 0;
	for (left = 0; left < (n / 2); left++)
		{
			arr[left] = arr[left] ^ arr[right];
			arr[right] = arr[left] ^ arr[right];
			arr[left] = arr[left] ^ arr[right];
			right--;
		}
	for (i = 0; i <n; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}
int main()
{
	int n = 0;
	int input = 1;
	int*arr;
	printf("请输入你想要创建的数组大小：>\n");
	scanf("%d", &n);
	arr = (int*)malloc(n+1);
	while (input)
	{
		menu();
		printf("\n请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			init(arr,n);
			break;
		case 2:
			CLR(arr,n);
			break;
		case 3:
			reverse(arr,n);
			break;
		case 4:
			input = 0;
			break;
		default:
			printf("输入错误，请重新输入！\n");
		}
		//free(arr);
	}

	system("pause");
	return 0;
}