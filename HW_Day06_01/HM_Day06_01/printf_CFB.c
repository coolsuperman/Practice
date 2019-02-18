#define _CRT_SECURE_NO_WARNINGS 1
#include"printf_CFB.h"

void printf_CFB(int row)
{
	int i = 0;
	int j = 0;
	int shang = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= i; j++)
		{
			int shang = i*j;
			printf("%d*%d=%d  ", j, i, shang);
		}
			printf("\n\n");
		
	}
}