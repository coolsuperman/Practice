//���������ѣ�������һ���� Nim��Ϸ����������һ��ʯͷ��ÿ�����������õ� 1 - 3 ��ʯͷ�� �õ����һ��ʯͷ���˾��ǻ�ʤ�ߡ�����Ϊ���֣�
//�����Ǵ����ˣ�ÿһ���������Ž⡣ ��дһ�����������ж����Ƿ�����ڸ���ʯͷ�����������Ӯ����Ϸ��
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int canWinNim(int n)
{
	return n % 4;
}

int main()
{
	int num = 0;
	printf("һ���ж��ٿ�ʯͷ��\n");
	scanf("%d",&num);
	if (canWinNim(num))
		printf("Ӯ���ˣ�");
	else
		printf("����Ӯ\n");
	system("pause");
	return 0;
}