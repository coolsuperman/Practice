//��һ�����ݣ���һ����֮�������鶼�ǳɶԳ��ֵģ����ҳ��������
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int FindSingle(int *arr,int sz)
{
	int i = 0;
	int single =arr[0];
	for (i = 0; i < (sz-1); i ++)
	{
		single ^= arr[i + 1];
	}
	return single;
}

int main()
{
	int arr[] = {1,3,2,4,6,5,8,7,9,3,1,2,4,8,7,6,9};
	int sz = sizeof(arr)/sizeof(arr[0]);
	printf("signel is %d\n", FindSingle(arr,sz));
	system("pause");
	return 0;
}