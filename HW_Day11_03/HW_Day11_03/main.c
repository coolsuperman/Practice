//在屏幕上打印杨辉三角；
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>

void YHSJ(int num)
{
	assert(num<=50);
	int arr[50][50] = {0,1};
	int i = 0;
	int j = 0;
	for (i = 1; i <= num; i++)
	{
		/*int ret = (50 - i) / 2;
		while (ret--)
		{
			printf("    ");
		}*///美化失败；
		for (j = 1; j <= i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			if (arr[i][j] < 10)
				printf("%d    ", arr[i][j]);
			else if (arr[i][j] < 100)
				printf("%d   ", arr[i][j]);
			else if (arr[i][j] < 1000)
				printf("%d  ", arr[i][j]);
			else
				printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int num = 0;
	printf("几层？\n");
	scanf("%d", &num);
	YHSJ(num);
	system("pause");
	return 0;
}