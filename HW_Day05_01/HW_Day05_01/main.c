// ʵ�ֲ�������Ϸ.
//˼·��������switch caseʵ�ֲ˵���ѡ����ѡ�������Ϸ��ʹ��srand��������������������������������жϣ�
//Debug log:
//*****1.switch case�����ִ��break������Ҫ��while������жϣ�
//*****2.srand����game������ÿ��game�е�rand�����ö���ʹ��һ���µ�seedֵ��time�����ã�ʹ�õõ�������������������srand����main�еõ����ƣ�
//ע��rand������ʹ�ã�������Ҫ��srand�����ṩһ��unsigned int���͵Ŀɱ仯seed��2byteȡֵ��Χ0~65535����sand����0~32767�����ֵ;����ѡ��ץȡ�������ʱ��;
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu();
void game();

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	menu();
	do
	{
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("��Ϸ�˳���...\n");
			break;
		default:
			printf("��������������!\n");
			break;
		}
	} while (input != 2);
	
	system ("pause");
	return 0;
}

void menu()
{
	printf("******************\n");
	printf("******1.��ʼ******\n");
	printf("******2.�˳�******\n");
	printf("******************\n");
}

void game()
{
	int i= 1;
	int input = 0;
	i = rand() % 100;
	printf("��²��Ƕ��٣�\n:>");
	for (; i != input;)
	{
		scanf("%d", &input);
		if (i > input)
		{
			printf("��С�ˣ�\n:>");
		}
		else if (i < input)
		{
			printf("�´��ˣ�\n:>");
		}
	}
	printf("��ϲ�㣬������!\n");
	//printf("%d", i);
}
