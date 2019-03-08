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
			printf("密码正确，登陆中...\n");
			break;
		}
		else
		{
			printf("输入错误，请重新输入！\n");
		}
	}
	if (i >= 3)
	{
		printf("三次密码错误，退出程序！！/n");
	}
	
	system("pause");
	return 0;
}