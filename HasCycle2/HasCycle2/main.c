//求带环链表的环入口
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

struct SLNode *detectCycle(struct SList *head) {
	struct SLNode *fast = head->first;
	struct SLNode *slow = head->first;
	if (!head) {
		return NULL;
	}
	while (1) {
		fast = fast->next;
		if (fast == NULL) {
			return NULL;
		}
		slow = slow->next;
		fast = fast->next;
		if (fast == NULL) {
			return NULL;
		}
		if (fast == slow) {
			break;
		}
	}
	struct SLNode *n1 = head->first;
	struct SLNode *n2 = slow;
	while (n1 != n2) {
		n1 = n1->next;
		n2 = n2->next;
	}
	return n2;
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
	SLNode*get = detectCycle(&test);
	system("pause");
	return 0;
}