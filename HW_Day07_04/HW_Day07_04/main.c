//��дһ������reverse_string(char*string)���ݹ�ʵ�֣��������ַ����е��ַ��������У�����ʹ�ÿ���Ĳ���������
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void reverse_string(char*string)
{
	if (*(string++) != '\0')
	{
		reverse_string(string);
		printf("%c", *(string-1));
	}
}

int main()
{
	int i=0;
	char arr[] = "965432";
	int sz = sizeof(arr) / sizeof(arr[0]);
	reverse_string(arr);
	printf("\n");
	//printf("\n%d\n", sz);
	for (i = 0; i < sz; i++)
	{
		printf("%c", arr[i]);
	}
	system("pause");
	return 0;
}