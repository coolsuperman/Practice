//删除链表中等于给定值 val 的所有节点。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

typedef struct List
{
	struct ListNode*first;
}List;

struct ListNode* removeElements(List* list, int val)
{
	if (list->first == NULL)
	{
		return NULL;
	}
	struct ListNode* last = list->first;
	struct ListNode* go = list->first->next;
	while (go != NULL)
	{
		if (go->val == val)
		{
			last->next = go->next;
			free(go);
			go = last->next;
		}
		else
		{
			last = go;
			go = go->next;
		}
	}
	if (list->first->val == val)
	{
		struct ListNode* check = list->first;
		list->first = list->first->next;
		free(check);
	}
	return list->first;
}

void PushValue(List*list, int value)
{
	struct ListNode* block = (struct ListNode*)malloc(sizeof(struct ListNode));
	block->val = value;
	block->next = list->first;
	list->first = block;
}

void ListInit(List*list)
{
	assert(list != NULL);
	list->first= NULL;
}

int main()
{
	List test;
	ListInit(&test);
	PushValue(&test, 5);
	PushValue(&test, 4);
	PushValue(&test, 3);
	PushValue(&test, 2);
	PushValue(&test, 1);
	struct ListNode*a = removeElements(&test, 5);
	system("pause");
	return 0;
}