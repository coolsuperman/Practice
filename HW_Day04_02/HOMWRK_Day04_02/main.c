//���0~999֮�����С�ˮ�ɻ��������������
//�㷨������ˮ�ɻ��������Կ�����ƣ���ÿһ�����ĸ�λ��ʮλ����λ���������Ȼ����pow�����������������Ӻ��ԭ���Ƚ��жϣ�
//debug log:
//********1.��Ϊˮ�ɻ�����Ϊһ����λ��������Ϊ��ʡʱ��ֱ�Ӵ�100��ʼ��

#include <stdio.h>
#include<math.h>

int main()
{
	int i = 0;
	int BW = 0;
	int SW = 0;
	int GW = 0;
	int sum = 0;
	int count = 0;
	for (i = 100; i <= 999; i++)
	{
		BW = i / 100;
		SW = (i % 100) / 10;
		GW = (i % 100) % 10;
		sum = pow(GW, 3) + pow(SW, 3) + pow(BW, 3);
		if (i == sum && BW != 0)
		{
			printf("%d  ", i);
			count++;
		}
	}
	printf("\n�ܼƣ�%d��\n", count);
	system("pause");
	return 0;

}