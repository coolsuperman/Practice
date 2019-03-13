//���Ӵ����������
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDatatype;


typedef struct RSLNode
{
	SLDatatype value;
	struct RSLNode* next;
	struct RSLNode* radom;
}RSLNode;
typedef struct SList
{
	struct RSLNode* first;
}SList;

void SLInit(SList *list)
{
	assert(list);
	list->first = NULL;
}

RSLNode* SLBuyMem(SLDatatype value)
{
	RSLNode* node = (RSLNode*)malloc(sizeof(RSLNode) * 1);
	assert(node);
	node->value = value;
	return node;
}

void SLPushFront(SList *list, SLDatatype value)
{
	assert(list);
	RSLNode* get = SLBuyMem(value);
	get->next = list->first;
	get->radom = get;//�������������Աָ������
	list->first = get;
}

RSLNode* CopyRadomList(SList*list) 
{
	if (list->first == NULL)
	{
		return NULL;
	}
	RSLNode*go = list->first;
	for (RSLNode*go = list->first; go != NULL; go = go->next->next)
	{
		RSLNode*node = (RSLNode*)malloc(sizeof(RSLNode));
		node->next = go->next;
		go->next = node;
		node->radom = NULL;
		node->value = go->value;
	}//�½ڵ�����Ͻڵ���棻
	go = list->first;
	while (go!=NULL)
	{
		RSLNode*change = go->next;
		if (go->radom != NULL)
		{
			change->radom = go->radom->next;
		}
		go = go->next->next;
	}//����radom
	go = list->first;
	RSLNode*result = go->next;
	while (go!=NULL)
	{
		RSLNode*node = go->next;
		go->next = go->next->next;
		if (node->next != NULL)
		{
			node->next = node->next->next;
		}
		go = go->next;
	}//�����Ͻڵ㣻
	return result;
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
	RSLNode* back = CopyRadomList(&test);
	system("pause");
	return 0;
}