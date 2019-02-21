//调整数组使奇数全部位于偶数前面
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

void DigitArr(int *tpr,int len)
{
	int *end = tpr + len - 1;
	int temp;
	while (end > tpr)
	{
		if (*tpr % 2 == 0)
		{
			while (*(end) % 2 == 0 && end>tpr)//若无后面条件此处在数组全偶数下可能存在循环越界；
			{
				end--;
			}
			if (*(end) % 2 != 0)//若全偶则不改变原元素顺序；
			{
				temp = *tpr;
				*tpr = *end;
				*(end--) = temp;
			}
		}
		tpr++;
	}
}

int main()
{
	int arr[] = {1,33,22,554,34,11,89,55};
	int len = sizeof(arr) / sizeof(arr[0]);
	DigitArr(arr,len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}