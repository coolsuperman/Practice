//ģ��⺯��qsortʵ��ͨ��ð������
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


void BubbleSort(int *dest, int sz)//ֻ���int�����ݵ�һ��ð������
{
	for (int i = 0; i < sz-1; i++)//����
	{
		for (int j = 0; j < sz - i - 1; j++)//ÿ���жϼ���Ԫ��
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

int compare_char(const void*elem1, const void*elem2)//��Ҫʹ�����Լ�����
{
	return *(char*)elem1 - *(char*)elem2;
}

int compare_int(const void*elem1,const void*elem2)//��Ҫʹ�����Լ�����
{
	return *(int*)elem1 - *(int*)elem2;
}

int compare_struct(const void*elem1, const void*elem2)//��Ҫʹ�����Լ�����
{ 
	return ((struct Student*)elem1)->age - ((struct Student*)elem2)->age;
}

void swap(char*elem1, char*elem2,unsigned int width)//���ֽڽ������������Բ����жϵ�����ʲô���͵�����
{
	assert(elem1 != NULL && elem2 != NULL);
	for (unsigned int i = 0; i < width; i++)
	{
		char temp = *(elem1 + i);
		*(elem1 + i) = *(elem2 + i);
		*(elem2 + i) = temp;
	}
}

void Common_BubbleSort(void*basic, int sz,unsigned int width, int(*cmp)(const void*elem1, const void*elem2))//������������ð������֮ͬ�������жϽ���������
{
	for (int i = 0; i < sz - 1; i++)//����
	{
		for (int j = 0; j < sz - i - 1; j++)//ÿ���жϼ���Ԫ��
		{
			if ((cmp((char*)basic+j*width,(char*)basic+(j+1)*width))>0)
			{
				swap((char*)basic + j*width, (char*)basic + (j + 1)*width,width);
			}
		}
	}
}


int main()//�ֱ�ʹ�����Σ��ַ����ͽṹ����в���
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