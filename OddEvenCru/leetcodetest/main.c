#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int* sortArrayByParityII_2(int* A, int ASize, int* returnSize)//��̬�ڴ淨
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

int* sortArrayByParityII(int* A, int ASize, int* returnSize)//ֱ��ͨ��˫ָ�뷨�޸�ԭ���飬ǰָ����ż������ָ���������
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
//{//��ΪĬ�Ͽ϶���������������������ʱ��ֻ���ܴ���һ�������Կ���ʹ�����ַ���
//	int count = 1;//�ӵ�һ������ʼcount=1��������ͬ�ľͼ�1��������ͬ�ľͼ�1������0�����»�������ʼ�����������ҵ������Ǹ�
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