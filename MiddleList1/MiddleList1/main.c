#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDatatype;
typedef struct SLNode
{
	SLDatatype value;
	struct SLNode* next;
}SLNode;
typedef struct SList
{
	struct SLNode* first;
}SList;

void SLInit(SList *list)
{
	assert(list);
	list->first = NULL;
}

SLNode* SLBuyMem(SLDatatype value)
{
	SLNode* node = (SLNode*)malloc(sizeof(SLNode) * 1);
	assert(node);
	node->value = value;
	return node;
}

void SLPushFront(SList *list, SLDatatype value)
{
	assert(list);
	SLNode* get = SLBuyMem(value);
	get->next = list->first;
	list->first = get;
}

SLNode* middleNode(SList *list)
{
	SLNode *fast = list->first;
	SLNode *low = list->first;
	while (fast->next)
	{
		fast = fast->next;
		low = low->next;
		if (fast->next)
		{
			fast = fast->next;
		}
	}
	return low;
}

int main()
{
	SList test;
	SLInit(&test);
	SLPushFront(&test, 5);
	SLPushFront(&test, 4);
	SLPushFront(&test, 3);
	SLPushFront(&test, 2);
	SLPushFront(&test, 1);
	SLPushFront(&test, 0);
	SLNode* back = middleNode(&test);
	system("pause");
	return 0;
}