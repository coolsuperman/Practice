//��дһ�����򣬿���һֱ���ռ����ַ�������Сд�����д�����ܴ�д���Сд�����Ϊ�����������
//˼·����ȡ������ַ�����ת��Ϊint�͵�ASCIIֵ���������������
//Debug log:
//*****1.��ʹ��getchar()��ȡ�ַ����һ��printf�������Σ������ж�Ϊgetchar�������ַ����enter��Ҳ�����˼��̻������ڲ��ڵ�һ���ַ�����ȡ�����̱���ȡ������ʹ����if�������
//ɸ��enter��֮��δ�õ����ƣ�δ�ܽ�������⣻
//*****2.��ʹ����getch()��getche()ǰ�߲���ʾ���룬����Ҫ�ȴ��س�ֱ�Ӷ�ȡ�����߲���Ҫ�س�ֱ������������ʾ���룩�������߽�getchar���޻�������

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


int main()
{
	//char  a = 'a';
	//int b = a;
	//printf("%c", b);
	//char character = '0';
	int number = 0;
	for (;;)
	{
		if (number != 13)//ɸ��enter��
		{
			printf("\n�����뵥���ַ���\n");
		}
		number = getche();//����Ҫ�س�ֱ����������
		//number = getch();//����ʾ���룬����Ҫ�س���
		//number = getchar();//��ʾ���룬��Ҫ�س����һس�Ҳ����ڻ������ڵȴ���һ���ַ�����ȡ�����̱���ȡ��
		 if (number >= 65 && number <= 90)
		{
			printf("\n%c\n", number + 32);
		}
		else if (number >= 97 && number <= 122)
		{
			printf("\n%c\n", number - 32);
		}
		else if (number >= 48 && number <= 57)
		{

		}
		else
		{

		}
	}

	system("pause");
	return 0;

}