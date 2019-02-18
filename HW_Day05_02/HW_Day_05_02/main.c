//在整形有序数组中查找想要的数字，找到了返回下标，找不到返回-1（折半查找）；
//思路：又称二分查找法，因为是有序数列，所以可以先得到数组长度用两端的下标直接得到中间值与目标数比较大小，然后缩小范围以此类推直至锁定目标数或未找到目标数,
//大幅减小时间复杂度；
//Debug log：
//*****1.在使用mid =  (right - left) / 2;语句时程序进入bin_search函数时卡死；替换为mid = left + (right - left) / 2;后实现功能；
//*****原因：逻辑错误，导致在while循环内arr[mid]访问到数组外的非法地址，程序崩溃;


#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int bin_search(int*arr[],int x,int sz);


int main()
{
	int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int x = 0;
	int sign = 0;
	int sz = sizeof arr / sizeof arr[0];
	printf("请输入你想要查找的数(1~15)：>");
	scanf("%d", &x);
	sign = bin_search(arr, x, sz);
	printf("\n要查找的数在数组中的下标为：%d\n", sign);
	system("pause");
	return 0;
}

int bin_search(int* arr[], int x, int sz)
{
	int left = 0;
	int right = sz - 1;
	int mid = 0;
	while (left <= right)
	{
		//mid =  (right - left) / 2;
		mid = left + (right - left) / 2;
		if (x > arr[mid])
		{
			left = mid + 1;
		}
		else if (x < arr[mid])
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}