//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮��õ����ַ�����
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int LevorotationJudge(char*long_arr,char* scr, int sz)
{
	int count = 0;
	char*scr_copy = scr;
	while (*(long_arr) != '\0')
	{
		if (count < sz)
		{
			if (*(long_arr) == *(scr_copy++))
			{
				count++;
			}
			else
			{
				count = 0;
				scr_copy = scr;
			}
			long_arr++;
		}
		else
		{

			return 1;
		}
	}
	return 0;
}
char* Loop_arr(char*arr, int sz)//���ABCDEFABCDEF
{
	char* long_arr = (char *)malloc(sizeof(char)*(sz * 2) + 1);
	int i = 2, j = 0;
	while (i--)
	{
		for (j = 0; j < sz; j++)
		{
			*(long_arr++) = *(arr + j);
		}
	}
	*(long_arr) = '\0';
	long_arr -= sz * 2;
	/*for (i = 0; i < sz * 2; i++)
	{
	printf("%c", long_arr+i);
	*/
	return long_arr;
}

int main()
{
	char arr[] = "ABCDEF";
	char s1[] = "CDEFAB";
	char s2[] = "abcdef";
	char s3[] = "ADCBFE";
	char* scr[3] = { s1,s2,s3 };
	int sz=sizeof(arr) / sizeof(arr[0])-1;
	for (int i = 0; i < 3; i++)
	{
		if (LevorotationJudge(Loop_arr(arr,sz),scr[i], sz))
		{
			printf("��%d������Ϊarr��������  \n", i + 1);
		}
		else
		{
			printf("��%d�����鲻Ϊarr�������� \n", i + 1);
		}
	}
	system("pause");
	return 0;
}