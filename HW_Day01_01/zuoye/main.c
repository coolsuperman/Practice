#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void pf_Ss(int begain, int end);
int main()
{
	int begain;
	int end;
	printf("Input begain&end:\n");
	scanf("%d %d", &begain, &end);
	pf_Ss(begain,end);
	system("pause");
	return 0;
}

void pf_Ss(int begain, int end)
{
	int i = 0;
	int j = 0;
	
	for (i = begain; i <= end; i++)
	{
		int count = 0;
		for (j = 1; j < i; j++)
		{
			int judge_ZC;
			judge_ZC = i%j;
			if (judge_ZC == 0)
			{
				count++;
			}
		}
		if (count == 1)

		{
			printf("%d\n", i);
		}
	}
}