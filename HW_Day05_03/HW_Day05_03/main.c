//编写代码模拟三次密码输入的场景；最多只能输入三次密码，正确提示登录成功，错误重新输入，最多输入三次，均错提示退出；
//思路：使用strcmp函数将默认密码与用户输入密码进行比较，若相同返回0；
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
		printf("请输入密码：>\n");
		scanf("%s", input);
		if (i == 3)
		{
			printf("输错三次！退出中...\n");
			break;
		}
		else if (strcmp(password, input) == 0)
		{
			printf("输入正确！登陆中...\n");
			break;
		}
		else
		{
			printf("输入错误，请重新输入！\n");
		}
	}
	system("pause");
	return 0;
}