//不使用运算符 + 和 - ???????，计算两整数 ???????a 、b ???????之和。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int getSum(int a, int b) {
//    int sum,carry;
//    do{
//        sum =a^b;
//        carry = (a&b)<<1;
//        a = sum;
//        b = carry;
//    }while(b!=0);
//    return sum;
//}
int getSum(int a, int b) {
	if (a == 0) { return b; }
	if (b == 0) { return a; }
	unsigned int _a = (unsigned int)a;
	unsigned int _b = (unsigned int)b;
	unsigned int sum;
	while (_b) {
		sum = _a^_b;
		_b = (_a&_b) << 1;
		_a = sum;
	}
	return (int)sum;
}

int main()
{
	int a = -1, b = 2;
	printf("%d", getSum(a, b));
	system("pause");
	return 0;
}