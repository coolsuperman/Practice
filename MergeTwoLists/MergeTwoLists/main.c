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

struct SLNode* mergeTwoLists( SList* l1, SList* l2) {
	if (!l1->first)
	{
		return l2->first;
	}
	else if (!l2->first) {
		return l1->first;
	}
	struct  SLNode* result = NULL;
	struct  SLNode* result_last = NULL;
	struct  SLNode* cur1 = l1->first;
	struct  SLNode* cur2 = l2->first;
	while ((cur1 != NULL) && (cur2 != NULL)) {
		if (cur1->value <= cur2->value) {
			if (result_last != NULL) {
				result_last->next = cur1;
				result_last = cur1;
			}
			else {
				result = cur1;
				result_last = cur1;
			}
			cur1 = cur1->next;
		}
		else {
			if (result_last != NULL) {
				result_last->next = cur2;
				result_last = cur2;
			}
			else {
				result = cur2;
				result_last = cur2;
			}
			cur2 = cur2->next;
		}
	}
	if (cur1 != NULL) {
		result_last->next = cur1;
	}
	else {
		result_last->next = cur2;
	}
	return result;
}
int main()
{
	SList test,test2;
	SLInit(&test);
	SLPushFront(&test, 5);
	SLPushFront(&test, 4);
	SLPushFront(&test, 3);
	SLPushFront(&test, 2);
	SLPushFront(&test, 1);
	SLPushFront(&test, 0);
	SLInit(&test2);
	SLPushFront(&test2, 5);
	SLPushFront(&test2, 4);
	SLPushFront(&test2, 3);
	SLPushFront(&test2, 2);
	SLPushFront(&test2, 1);
	SLPushFront(&test2, 0);
	SLNode* back = mergeTwoLists(&test, &test2);
	system("pause");
	return 0;
}