//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ����֮�ͣ�����a��һ�����֣�

//�㷨��nΪǰ����֮�ͣ�Sn_nΪSn���������ڱ����о�Ϊ5��ͨ������forѭ��ʵ�֣���һ��Ϊ��a����1~5��ֵ���ڶ���Ϊ����Sn��ֵ��
//debug log ��
//*******1.�ڵ�һ��Snȫ�������ʱ��δ��sn���㣻���µڶ���Sn��ʼ����ʱֱ����11111�ϼ����ӣ����ս������

#include<stdio.h>
#include<math.h>

int Sum_Sn(int n, int Sn_n);

int main()
{
	int n = 5;
	int Sn_n = 5;
	int sum = 0;
	sum = Sum_Sn(n, Sn_n);
	printf("��Ϊ��%d\n", sum);
	system("pause");
	return 0;
}

int Sum_Sn(int n, int Sn_n)
{
	int i = 0;
	int j = 0;
	int sum = 0;
	int Sn = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= Sn_n; j++)
		{
			Sn += i*pow(10, j - 1);
			sum += Sn;
		}
		Sn = 0;
	}
	return sum;
}