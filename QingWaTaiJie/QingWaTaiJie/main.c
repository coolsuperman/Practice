//������������¥�ݡ���Ҫ n ������ܵ���¥����ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int climbStairs(int n)
{
	//if(n<0){return 0;}
	//if(n==0){return 1;}
	//else
	//{
	//    return climbStairs(n-1)+climbStairs(n-2);
	//}//�ݹ���ô������
	int a = 1, b = 2, c = 0;
	if (n <= 2) { return n; }
	else
	{
		for (int i = 3; i <= n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}

}
int main()
{
	int num = 0;
	scanf("%d",&num);
	printf("%d", climbStairs(num));
	system("pause");
	return 0;
}