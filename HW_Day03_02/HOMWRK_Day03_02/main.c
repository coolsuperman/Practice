//计算1/1-1/2+1/3-1/4+1/5......+1/99-1/100的值。
//算法：原式等于1/1*2+1/3*4......1/99*100.
//debug log:
//*****1.float有效数字小数点后6位，double有效数字小数点后15位。
//*****2.若想使结果有效，运算元素类型必须与运算结果储存变量元素类型一致才可以得到有效计算。
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float i = 0.0;
	float sum = 0.0;
	for (i = 1; i <= 100; i += 2)
	{
		sum +=1 / (i*(i + 1));
	}
	printf("%f", sum);
	system("pause");
	return 0;
}