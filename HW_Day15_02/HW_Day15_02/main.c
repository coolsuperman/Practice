//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ
//�����ǿ���������ƿ��һƿ��ˮҲ����˵��������ƿ����һ��Ǯ��20ԪǮ�������������ƿ���ֻ����10Ԫ��10���˺���������ֻ���5ԪǮ���ݴ����ǾͿ�����Ƶݹ麯����
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int HowMany_recourse(int money,int signal)//�ݹ��㷨
{
	if (signal == 2)
	{
		money += 1;
		signal = 0;
	}
	if (money <1)
	{
		return 0;
	}
	else
	{
		return money + HowMany(money / 2,money%2+signal);
	}
}

int HowMany(int money)//�ǵݹ�
{
	int total = money;
	int empty = money;
	while (empty > 1)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	return total;
}

int main()
{
	int num = 0;
	printf("���ж���Ǯ��\n");
	scanf("%d", &num);
	printf("���Ժ�%dƿ��ˮ\n", HowMany_recourse(num,0));
	printf("���Ժ�%dƿ��ˮ\n", HowMany(num));
	printf("���Ժ�%dƿ��ˮ\n",2*num-1);//����ʽ
	system("pause");
	return 0;
}