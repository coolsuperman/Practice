//�ձ�������һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ��е�һ����һ��Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ң�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵��
//��֪������˵���滰��1����˵�˼ٻ�����дһ��������ȷ��˭�����֣�
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
//								printf("A������\n");
//							}
//							else if (b == 1)
//							{
//								printf("B������\n");
//							}
//							else if (c == 1)
//							{
//								printf("C������\n");
//							}
//							else
//							{
//								printf("D������\n");
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