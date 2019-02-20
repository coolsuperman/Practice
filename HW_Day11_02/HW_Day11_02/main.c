//日本发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯中的一个，一下为4个嫌疑犯的供词。
//A说：不是我；
//B说：是C；
//C说：是D；
//D说：C在胡说；
//已知三个人说了真话，1个人说了假话，请写一个程序来确定谁是凶手；
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main()
//{
//	int a, b, c, d;
//	for (a = 0; a <= 1; a++)
//	{
//		for (b = 0; b <= 1; b++)
//		{
//			for (c = 0; c <= 1; c++)
//			{
//				for (d = 0; d <= 1; d++)
//				{
//					if ((a == 0) + (c == 1) + (d == 1) + (d == 0) == 3)
//					{
//						if (a + b + c + d == 1)
//						{
//							if (a == 1)
//							{
//								printf("A是凶手\n");
//							}
//							else if (b == 1)
//							{
//								printf("B是凶手\n");
//							}
//							else if (c == 1)
//							{
//								printf("C是凶手\n");
//							}
//							else
//							{
//								printf("D是凶手\n");
//							}
//							system("pause");
//							return 0;
//						}
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//	return 1 ;
//}

int main()
{
	int killer = 0;
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
		{
			printf("killer is %c", killer);
			system("pause");
			return 0;
		}
	}
	return 1;
}