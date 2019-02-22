//一个数组中只有两个数组是出现一次，其他所有数都出现了两次，找出这个两数字
//思路：由题知只有两个数不是成对出现的，我们将所有的数按位异或，得到的就是这两个独数按位异或的值，这时这个值里的二进制位里的1代表两独数的该位不相同，我们将其中一个不同位
//找出来，然后以此为据将整个数组分成两组，这两个独数必然各自被分在一组中，又因为其他数都是成对出现的，这时我们再将每一组都按位异或，就可以分别得到独数；
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void CheckSignel(const int*arr, int sz, int* a, int* b)
{
	int i = 0,both =0,flag =1;
	for (i = 0; i < sz; i++)
	{
		both ^= arr[i];
	}
	while (both)//这里使用flag从地位向高位查找1；得到后立刻跳出；
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