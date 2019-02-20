//编写函数：unsigned int reverse_bit(unsigned int value);这个函数的返回值value的二进制位模式从左到右翻转后的值；
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
	printf("请输入你想要反转的值:>\n");
	scanf("%u", &value);
	printf("翻转后的值:>%u\n", reverse_bit(value));
	system("pause");
	return 0;
}