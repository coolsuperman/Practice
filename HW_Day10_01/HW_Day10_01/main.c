//写一个函数返回参数2进制中1的个数;函数原型int count_one_bits(unsigned int value)
//思路：整形数据右移时，我们知道是从左边补符号位，而无符号整型数据右移时，是从左边补零，当需要判断value时只需要向右移动位数然后模2便可以判断这一位是不是1；然后计数器加一
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//#include<assert.h>
//#include<climits>

int count_one_bits(const unsigned int value)
{
	//assert(value<=UINT_MAX);value达到最大值时会溢出，所以没用；
	//assert(value >= 0);
	int i = 32;
	int count = 0;
	while (i--)
	{
		count += (value >> i) % 2;
	}
	return count;
}

int main()
{
	unsigned int num = 0;
	int value = 0;
	printf("请输入你期望的数:>\n");
	scanf("%u", &num);
	value = count_one_bits(num);
	printf("二进制中1的个数为：>%d\n", value);
	system("pause");
	return 0;
}