//�������������Լ������С��������
//�㷨�����Լ����ȻС������������С�ģ��ҿɱ�������ͬʱ��������С��������Ȼ��������������С�ģ��ҿ�ͬʱ��������������
#include<stdio.h>

void Max_GYS(int a, int b);
void Min_GBS(int a, int b);

int main()
{
	int a = 0;
	int b = 0;
	scanf_s("%d %d",&a,&b);
	Max_GYS(a, b);
	Min_GBS(a, b);
	system("pause");
	return 0;
}

void Max_GYS(int a, int b)
{
	int i = 0;
	if (a < b)
	{
		i = a;
	}
	else
	{
		i = b;
	}
	for (;i>=1; i--)
	{
		if (a%i == 0 && b%i == 0)
		{
			printf("���Լ����%d\n", i);
			break;
		}
	}

}
void Min_GBS(int a, int b)
{
	int i = 0;
	if (a < b)
	{
		i = a;
	}
	else
	{
		i = b;
	}
	for (; ; i++)
	{
		if (i%a == 0 && i%b == 0)
		{
			printf("��С��������%d\n", i);
			break;
		}
	}

}
