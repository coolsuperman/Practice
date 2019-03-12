//编写一个程序，找到两个单链表相交的起始节点。
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

int getlongth(struct SLNode *target) {
	int count = 0;
	while (target != NULL) {
		count++;
		target = target->next;
	}
	return count;
}
struct SLNode *getIntersectionNode(SList *headA, SList *headB) {
	struct SLNode* LongHead;
	struct SLNode* shortHead;
	int lenA = getlongth(headA->first);
	int lenB = getlongth(headB->first);
	int cha = 0;
	if (lenA >= lenB) {
		cha = lenA - lenB;
		LongHead = headA->first;
		shortHead = headB->first;
	}
	else {
		cha = lenB - lenA;
		LongHead = headB->first;
		shortHead = headA->first;
	}
	for (int i = 0; i<cha; i++) {
		LongHead = LongHead->next;
	}
	while (LongHead != shortHead) {
		shortHead = shortHead->next;
		LongHead = LongHead->next;
		if (!LongHead) {
			return NULL;
		}
	}
	return LongHead;
}

int main()
{
	SList test,test2;
	SLInit(&test);
	SLInit(&test2);
	SLPushFront(&test, 5);
	SLPushFront(&test, 4);
	SLPushFront(&test, 3);
	SLPushFront(&test, 2);
	SLPushFront(&test, 1);
	SLPushFront(&test, 0);
	SLPushFront(&test2, 5);
	SLPushFront(&test2, 4);
	SLPushFront(&test2, 3);
	test2.first->next->next = test.first->next->next->next;
	SLNode* back = getIntersectionNode(&test, &test2) ;
	system("pause");
	return 0;
}