#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void pf_CFB();
int main()
{
	pf_CFB();
	system("pause");
	return 0;
}
void pf_CFB()
{
	int i;
	int j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			int Ji = 0;
			Ji = i*j;
			
			printf("%d*%d=%d  ", j, i, Ji);
            if (i == j)
			{
				printf("\n");
			}
		}
	}
}