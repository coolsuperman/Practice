//����һ����������дһ���������ж����Ƿ��� 2 ���ݴη���
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int isPowerOfTwo(int n)
{
	if (n>0)
	{
		return !(n&(n - 1));
	}
	return 0;
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	if (isPowerOfTwo(num))
	printf("�Ƕ����ݴη�\n");
	else
		printf("����2���ݴη�\n");
	system("pause");
	return 0;
}