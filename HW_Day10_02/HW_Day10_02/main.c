//��ȡһ�����Ķ����������е�����ż��λ������λ���ֱ�������������У�
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>

enum number
{
	even ,//��Ҫ����λ��
	odd //��Ҫż��λ��
};

int* get_bit(const  int value,int* arr,int want)//����const����ֹ����������иı���value��ֵ��
{
	assert(arr !=NULL);//��ֹ�����Ϣ��������һ����ָ�룻
	int *ret = arr;
	int i = 0;
	for (i = want; i < 32; i+=2)
	{
		*(arr++) = (value >> i) % 2;
	}
	return ret;
}

int main()
{
	int arr[16] = { 0 };
	int value = 0;
	int* tpr = arr;
	int i = 0;
	printf("����������������:>\n");
	scanf("%d", &value);
    get_bit(value, arr, even);
	printf("\nż���У�\n");
	for (i = 0; i < 16; i++)
	{
		if (i % 4 == 0)
		{
			printf(" ");//ÿ��λ�ո񷽱㿴�������
		}
		printf("%d", *(tpr++));
	}
	tpr = get_bit(value, arr, odd);
	printf("\n�����У�\n");
	for (i = 0; i < 16; i++)
	{
		if (i % 4 == 0)
		{
			printf(" ");
		}
		printf("%d", *(tpr++));
	}
	printf("\n");
	system("pause");
	return 0;
}