#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void exchange(int a, int b);
int main()
{
	int a;
	int b;
	printf("inputa&b:\n");
	scanf("%d%d", &a, &b);
    exchange(a, b);
	system("pause");
}
void exchange(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("a=%d,b=%d", a, b);

}