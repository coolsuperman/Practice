//求出0~999之间所有“水仙花数”，并输出；
//算法：根据水仙花数的特性可以设计：将每一个数的个位、十位、百位分离出来，然后用pow函数算出各自立方相加后和原数比较判断；
//debug log:
//********1.因为水仙花数必为一个三位数，所以为节省时间直接从100开始；

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
	printf("\n总计：%d个\n", count);
	system("pause");
	return 0;

}