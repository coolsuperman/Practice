//反转一个单链表
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};

typedef struct List
{
	struct ListNode* first;
}List;

struct ListNode* reverseList_2(List* list)
{
	struct ListNode* new = NULL;
	struct ListNode* go = list->first;
	while (go != NULL)
	{
		struct ListNode* temp = go;
		go = go->next;
		temp->next = new;
		new = temp;
	}
	return new;
}

struct ListNode* reverseList( List* list) //在得到节点时原位置直接改变
{
	if (list->first == NULL)
	{
		return list->first;
	}
	struct ListNode* prev = NULL;
	struct ListNode* next = list->first->next;
	for (struct ListNode* go = list->first; go != NULL;)
	{
		go->next = prev;
		prev = go;
		go = next;
		if (next != NULL)
		{
			next = next->next;
		}
	}
	return prev;
}

void PushValue(List*list,int value)
{
	struct ListNode* block = (struct ListNode*)malloc(sizeof(struct ListNode));
	block->val = value;
	block->next = list->first;
	list->first = block;
}

void ListInit(List*list)
{
	assert(list != NULL);
	list->first = NULL;
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
	struct ListNode*a = reverseList(&test);
	system("pause");
	return 0;
}