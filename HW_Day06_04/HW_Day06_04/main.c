#define _CRT_SECURE_NO_WARNINGS 1
//����һ�����飬ʵ��init��ʼ��empty����������飬ʵ��reverse���������������Ԫ�ص����ã�
//ע��malloc�������������ռ�ĺ���void *malloc(size_t size);���뵽����������δ����ʼ���Ŀռ䣻

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void menu()
{
	printf("*********************\n");
	printf("***1,��ʼ������*****\n");
	printf("***2,�������*******\n");
	printf("***3,����Ԫ������**\n");
	printf("***4,�˳�����*******\n");
	printf("*********************\n");
}
void init(int*arr, int n)
{
	int i = 0;
	printf("�������ʼ������Ԫ�أ�>\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("��ʼ���ɹ���\n");
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
	printf("��������գ�\n");
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
	printf("����������Ҫ�����������С��>\n");
	scanf("%d", &n);
	arr = (int*)malloc(n+1);
	while (input)
	{
		menu();
		printf("\n��ѡ��>");
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
			printf("����������������룡\n");
		}
		//free(arr);
	}

	system("pause");
	return 0;
}