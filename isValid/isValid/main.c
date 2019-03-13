//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。有效字符串需满足：左括号必须用相同类型的右括号闭合。左括号必须以正确的顺序闭合。注意空字符串可被认为是有效字符串。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct Stack {
	int array[10000];
	int top;
}Stack;

void stackInit(Stack*stack) {
	stack->top = 0;
}
int stackEmpty(Stack*stack) {
	return stack->top == 0 ? 1 : 0;
}
void stackPush(Stack*stack, int value) {
	stack->array[stack->top] = value;
	stack->top++;
}
void stackPop(Stack*stack) {
	stack->top--;
}
int stackTop(Stack*stack) {
	return stack->array[stack->top - 1];
}
int isValid2(char* s)
{
	Stack stack;
	stackInit(&stack);
	while (*s) {
		switch (*s) {
		case'{':
		case'[':
		case'(':
			stackPush(&stack, (int)*s);
			break;
		case'}':
		case')':
		case']': {
			if (stackEmpty(&stack)) {
				return 0;
			}
			char left = (char)stackTop(&stack);
			stackPop(&stack);
			if (!(left + 2 == *s || left + 1 == *s)) {
				return 0;
			}
			break;
		}
		default:
			break;
		}
		s++;
	}
	if (!stackEmpty(&stack)) {
		return 0;
	}
	return 1;
}
int isValid(char* s)
{
	int len = 0;
	while (*(s + len)) { len++; }
	char* ptr = (char*)malloc((len / 2) + 2);
	memset(ptr, 0, (len / 2) + 2);
	int i = 0, a = 0;
	for (i = 0; i<len; i++)
	{
		if ((*(s + i) == '(') || (*(s + i) == '{') || (*(s + i) == '['))
		{
			a++;
			*(ptr + a) = *(s + i);
		}
		else if ((*(s + i) == (*(ptr + a) + 1)) || (*(s + i) == (*(ptr + a) + 2)))
		{
			a--;
		}
		else
		{
			return 0;
		}
	}
	if (a)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	char a[] = "()";
	if (isValid(a))
	{
		printf("符合标准\n");
	}
	else
	{
		printf("No\n");
	}
	system("pause");
	return 0;
}