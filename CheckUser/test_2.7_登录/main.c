#include<stdio.h>
#include<string.h>

int main()
{
	char password[10] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("Please type the PassWord:>");
		//scanf_s("%s", &password[0]);
		password[10] = getchar();
		if (strcmp(password, "199805") == 0)
		{
			printf("������ȷ����½��...\n");
			break;
		}
		else
		{
			printf("����������������룡\n");
		}
	}
	if (i >= 3)
	{
		printf("������������˳����򣡣�/n");
	}
	
	system("pause");
	return 0;
}