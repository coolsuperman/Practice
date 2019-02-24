#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int* sortArrayByParityII_2(int* A, int ASize, int* returnSize)//动态内存法
{
	*returnSize = ASize;
	int *ptr = (int*)malloc(sizeof(int)*ASize);
	int i = 0, j = 1, loop = 0;
	for (loop = 0; loop<ASize; loop++)
	{
		if ((A[loop] & 1) == 0)
		{
			ptr[i] = A[loop];
			i += 2;
		}
		else
		{
			ptr[j] = A[loop];
			j += 2;
		}
	}
	return ptr;
}

int* sortArrayByParityII(int* A, int ASize, int* returnSize)//直接通过双指针法修改原数组，前指针检测偶数，后指针检测基数；
{
	*returnSize = ASize;
	int* A_go = A;
	int* A_back = A + ASize - 1;
	int temp = 0;
	if (ASize & 1 == 1)
	{
		A_back -= 1;
	}
	while ((A_go<A + ASize) && A_back >= A)
	{
		while (A_go<A + ASize && ((*A_go & 1) == 0))
		{
			A_go += 2;
		}
		while (A_back >= A && (*A_back & 1 == 1))
		{
			A_back -= 2;
		}
		if ((A_go<A + ASize) && A_back >= A)
		{
			temp = *A_go;
			*A_go = *A_back;
			*A_back = temp;
		}
		A_go += 2;
		A_back -= 2;
	}
	return A;
}
int main()
{
	int A[] = {4 ,1,2,1};
	//int numsSize = sizeof(nums) / sizeof(nums[0]);
	int returnSize = 0;
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", *(sortArrayByParityII(A, 4, &returnSize) + i));
	}
	system("pause");
	return 0;
}


//int majorityElement(int* nums, int numsSize) 
//{//因为默认肯定存在众数，且众数存在时，只可能存在一个，所以可以使用这种方法
//	int count = 1;//从第一个数开始count=1，遇到相同的就加1，遇到不同的就减1，减到0就重新换个数开始计数，总能找到最多的那个
//	int result = *nums;
//
//	for (int i = 1; i < numsSize; i++) 
//	{
//		if (*(nums + i) != result) 
//		{
//			if (count == 0) 
//			{
//				result = *(nums + i);
//				count = 1;
//				continue;
//			}
//			count--;
//		}
//		else {
//			count++;
//		}
//	}
//
//	return result;
//}