//��д������һ��1to100�����������г����˶��ٴ�����9
//�㷨������9�����־��ɼ�1��10���������������־������ڴ����ԡ�
#include<stdio.h>

int main()
{
	int count = 0;
	int i = 0;
	int flag = 0;
	for (i = 1; i <= 100; i++)
	{
		flag = 0;
		if ((i + 1) % 10 == 0)
		{
			flag = 1;
		}
		if (flag == 1)
		{
			count++;
		}
	}
	printf("����9������%d\n", count);
	system("pause");
	return 0;
}