//编写一个程序，可以一直接收键盘字符，接收小写输出大写，接受大写输出小写，如果为数字则不输出；
//思路：获取输入的字符后将其转化为int型的ASCII值后进行运算后输出；
//Debug log:
//*****1.在使用getchar()获取字符后第一句printf出现两次，初步判断为getchar将输入字符后的enter键也放入了键盘缓冲区内并在第一个字符被读取后立刻被读取，但在使用了if条件语句
//筛除enter键之后并未得到改善，未能解决该问题；
//*****2.故使用了getch()与getche()前者不显示输入，不需要等待回车直接读取；后者不需要回车直接输出结果（显示输入），且两者较getchar都无缓冲区；

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


int main()
{
	//char  a = 'a';
	//int b = a;
	//printf("%c", b);
	//char character = '0';
	int number = 0;
	for (;;)
	{
		if (number != 13)//筛除enter键
		{
			printf("\n请输入单个字符：\n");
		}
		number = getche();//不需要回车直接输出结果；
		//number = getch();//不显示输入，不需要回车；
		//number = getchar();//显示输入，需要回车，且回车也存放在缓存区内等待第一个字符被读取后立刻被读取；
		 if (number >= 65 && number <= 90)
		{
			printf("\n%c\n", number + 32);
		}
		else if (number >= 97 && number <= 122)
		{
			printf("\n%c\n", number - 32);
		}
		else if (number >= 48 && number <= 57)
		{

		}
		else
		{

		}
	}

	system("pause");
	return 0;

}