//һ��������ֻ�����������ǳ���һ�Σ����������������������Σ��ҳ����������
//˼·������ֻ֪�����������ǳɶԳ��ֵģ����ǽ����е�����λ��򣬵õ��ľ���������������λ����ֵ����ʱ���ֵ��Ķ�����λ���1�����������ĸ�λ����ͬ�����ǽ�����һ����ͬλ
//�ҳ�����Ȼ���Դ�Ϊ�ݽ���������ֳ����飬������������Ȼ���Ա�����һ���У�����Ϊ���������ǳɶԳ��ֵģ���ʱ�����ٽ�ÿһ�鶼��λ��򣬾Ϳ��Էֱ�õ�������
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void CheckSignel(const int*arr, int sz, int* a, int* b)
{
	int i = 0,both =0,flag =1;
	for (i = 0; i < sz; i++)
	{
		both ^= arr[i];
	}
	while (both)//����ʹ��flag�ӵ�λ���λ����1���õ�������������
	{
		if (both&flag)
		{
			break;
		}
		flag <<= 1;
	}
	for (i = 0; i < sz; i++)
	{
		if (arr[i] & flag)
		{
			(*a)^= arr[i];
		}
		else
		{
			(*b) ^= arr[i];
		}
	}

}

int main()
{
	int arr[]={ 1,3,2,5,4,6,7,9,8,1,2,3,4,5,7,9 };
	int sz = sizeof(arr)/sizeof(arr[0]),a=0,b=0;
	CheckSignel(arr, sz,&a, &b);
	printf("a = %d b = %d\n", a, b);
	system("pause");
	return 0;
}