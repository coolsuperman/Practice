//将三个数按从大到小输出。
//算法:冒泡排序
#include<stdio.h>

void Order_Output(int a, int b, int c);

int main()
{
	int a, b, c;
	printf("Please type the number(3):>\n");
	scanf_s("%d %d %d", &a, &b, &c);
	Order_Output(a, b, c);
	system("pause");
	return 0;
}

void Order_Output(int a, int b, int c)
{
	int i, j, temp;
	int arr[3] = { a, b, c };
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
		
	}
	printf("Max is %d,Mid is %d,Min is %d/n",arr[0], arr[1],arr[2]);

}