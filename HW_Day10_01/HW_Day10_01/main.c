//дһ���������ز���2������1�ĸ���;����ԭ��int count_one_bits(unsigned int value)
//˼·��������������ʱ������֪���Ǵ���߲�����λ�����޷���������������ʱ���Ǵ���߲��㣬����Ҫ�ж�valueʱֻ��Ҫ�����ƶ�λ��Ȼ��ģ2������ж���һλ�ǲ���1��Ȼ���������һ
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//#include<assert.h>
//#include<climits>

int count_one_bits(const unsigned int value)
{
	//assert(value<=UINT_MAX);value�ﵽ���ֵʱ�����������û�ã�
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
	printf("����������������:>\n");
	scanf("%u", &num);
	value = count_one_bits(num);
	printf("��������1�ĸ���Ϊ��>%d\n", value);
	system("pause");
	return 0;
}