//1.��λ�˶�Ա�μ���ʮ��̨��ˮ����������������Ԥ��������
//Aѡ��˵��B�ڶ����ҵ�����Bѡ��˵���ҵڶ���E���ģ�Cѡ��˵���ҵ�һ��D�ڶ���Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Σ�
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int Judge_Win()
{
	int a, b, c, d, e;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if ((b == 2 || a == 3) && (b == 2 || e == 4) && (c == 1 || d == 2) && (e == 4 || a == 1))
						{
							//if (a!=b&&a!=c&&a!=d&&a!=e&&b!=c&&b!=d&&b!=e&&c!=d&&c!=e&&d!=e)
							//if((a*b*c*d*e)==120)
							//{
								printf("A is %d;B is %d;C is %d;D is %d;E is %d", a, b, c, d, e);
								return 0;
							//}
						}
					}
				}
			}
		}
	}
	printf("û������������߼���\n");
	return 0;
}

int main()
{
	Judge_Win();
	system("pause");
	return 0;
}