//有一个字符数组为："student a am i",将内容修改为"i am a student ".不可以使用库函数，只能开辟有限个空间(空间个数和字符串长度无关)
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

int my_strlen(char const* data)
{
	assert(data != NULL);
	int count = 0;
	while (*(data++))
	{
		count++;
	}
	return count;
}


void ChangeOrderFrist(char*data)
{
	int temp = *data;
	int len = my_strlen(data);
	*data =*(data+len-1);
	*(data + len - 1) = '\0';
	if (my_strlen(data) > 1)
	{
		ChangeOrderFrist(data+1);
	}
	*(data +len- 1) = temp;
}

ChangeOrderSecond(char*data)
{
	char*check = data;
	int count_i = 1;
	int count = 0, count_stay= 0;
	char temp = 0;
	while (*(data) != '\0')
	{
		count = 0;
		while (*(data) != ' '&&*(data) != '\0')
		{
			count++;
			data++;
		}
		count_stay = count;
		while ((count--) > (count_stay>>1))
		{
			temp = *(data - count-1 );
			*(data - count - 1) = *(data- count_i);
			*(data-count_i) = temp;
			count_i++;
		}
		count_i = 1;
		if (*(data) != '\0')
		{
			data++;
		}
	}
}

int main()
{
	char data[] = "student a am i";
	int i = 0;
	int sz = my_strlen(data);
	char *p = &data[0];
	//int word_num = WordCheck(data, sz);
	 ChangeOrderFrist(data);
	 ChangeOrderSecond(data);
	for (i = 0; i < sz; i++)
	{
		printf("%c", *(p++));
	}
	system("pause");
	return 0;
}