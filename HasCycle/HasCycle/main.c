//给定一个链表，判断链表中是否有环。
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

int hasCycle(SList *head) {
	struct SLNode *fast = head->first;
	struct SLNode *slow = head->first;
	if (!head->first) {
		return 0;
	}
	while (1) {
		fast = fast->next;
		if (fast == NULL) {
			return 0;
		}
		slow = slow->next;
		fast = fast->next;
		if (fast == NULL) {
			return 0;
		}
		if (fast == slow) {
			return 1;
		}
	}
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
	if (hasCycle(&test))
	{
		printf("有环\n");
	}
	else
	{
		printf("没环\n");
	}
	system("pause");
	return 0;
}