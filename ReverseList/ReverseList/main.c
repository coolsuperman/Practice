//反转一个单链表。
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
	struct ListNode*head;
}List;

struct ListNode* reverseList_2(List* list)
{
	struct ListNode* new = NULL;
	struct ListNode* go = list->head;
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
	if (list->head == NULL)
	{
		return list->head;
	}
	struct ListNode* prev = NULL;
	struct ListNode* next = list->head->next;
	for (struct ListNode* go = list->head; go != NULL;)
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
	block->next = list->head;
	list->head = block;
}

void ListInit(List*list)
{
	assert(list != NULL);
	list->head = NULL;
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