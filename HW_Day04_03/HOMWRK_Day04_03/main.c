//求Sn=a+aa+aaa+aaaa+aaaaa的前五项之和，其中a是一个数字；

//算法：n为前几项之和，Sn_n为Sn的项数，在本题中均为5；通过两层for循环实现，第一层为给a赋予1~5的值；第二层为求单项Sn的值；
//debug log ：
//*******1.在第一个Sn全部项加完时，未将sn清零；导致第二项Sn开始计算时直接在11111上继续加，最终结果过大；

#include<stdio.h>
#include<math.h>

int Sum_Sn(int n, int Sn_n);

int main()
{
	int n = 5;
	int Sn_n = 5;
	int sum = 0;
	sum = Sum_Sn(n, Sn_n);
	printf("和为：%d\n", sum);
	system("pause");
	return 0;
}

int Sum_Sn(int n, int Sn_n)
{
	int i = 0;
	int j = 0;
	int sum = 0;
	int Sn = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= Sn_n; j++)
		{
			Sn += i*pow(10, j - 1);
			sum += Sn;
		}
		Sn = 0;
	}
	return sum;
}