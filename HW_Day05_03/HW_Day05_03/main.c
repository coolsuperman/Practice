//��д����ģ��������������ĳ��������ֻ�������������룬��ȷ��ʾ��¼�ɹ��������������룬����������Σ�������ʾ�˳���
//˼·��ʹ��strcmp������Ĭ���������û�����������бȽϣ�����ͬ����0��
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

int main()
{
	int i = 0;
	char password[] = "199805";
	char input[10] = { 0 };
	for (i = 1; i <= 3; i++)
	{
		printf("���������룺>\n");
		scanf("%s", input);
		if (i == 3)
		{
			printf("������Σ��˳���...\n");
			break;
		}
		else if (strcmp(password, input) == 0)
		{
			printf("������ȷ����½��...\n");
			break;
		}
		else
		{
			printf("����������������룡\n");
		}
	}
	system("pause");
	return 0;
}