//��д������unsigned int reverse_bit(unsigned int value);��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	unsigned int reversed = 0;
	while (i<sizeof(value) * 8)
	{
		if (((value >> i) &1)== 1)
		{
			reversed |= 1 << (sizeof(value) * 8-(i+1));
		}
		i++;
	}
	return reversed;
}

int main()
{
	unsigned int value = 0;
	printf("����������Ҫ��ת��ֵ:>\n");
	scanf("%u", &value);
	printf("��ת���ֵ:>%u\n", reverse_bit(value));
	system("pause");
	return 0;
}