#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void Judge_RN(int begain,int  end);

int main()
{
	int begain;
	int end;
	printf("input begain&end:\n");
	scanf("%d %d", &begain, &end);
    Judge_RN(begain, end);
	system("pause");
	return 0; 
}
void Judge_RN(int begain, int end)
{
	int i = 0;

	for (i = begain; i <= end; i++)
	{
		int judge_1 = 0;
		int judge_2 = 0;
		if (i % 4 == 0)
		{
			judge_1 = 1;
		}
		if (i % 1000 != 0)
		{
			judge_2 = 1;
		}
		if (judge_1 == 1 && judge_2 == 1)
		{
			printf("%d\n", i);
		}

	}
}