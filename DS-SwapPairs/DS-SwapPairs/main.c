#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDatatype;
typedef struct SLNode {
	SLDatatype value;
	struct SLNode* next;
}SLNode;
typedef struct SList {
	struct SLNode* first;
}SList;

void SLInit (SList *list) {
	assert (list);
	list->first = NULL;
}

SLNode* SLBuyMem (SLDatatype value) {
	SLNode* node = (SLNode*)malloc (sizeof (SLNode) * 1);
	assert (node);
	node->value = value;
	return node;
}

void SLPushFront (SList *list , SLDatatype value) {
	assert (list);
	SLNode* get = SLBuyMem (value);
	get->next = list->first;
	list->first = get;
}

 SLNode* swapPairs (struct SList* head) {//前插后插法
	SLNode*back , *set = head->first , *go , *pre = head->first , *next = NULL;//set：back链表的最后一个，pre是back的前一个，next存储go的next
	if ( !head->first ) { return NULL; }
	back = set;//返回新链表的首节点是set；
	int check = 1;//因为set从第二个节点开始所以初始化成1；
	for ( go = head->first->next; go != NULL; go = next ) {
		next = go->next;
		if ( check == 0 ) {//check=0时表示为交换两个数的第一个数，选择尾插在set处；
			go->next = NULL;
			set->next = go;
			check = 1;
			pre = set;
			set = set->next;//此情况下pre与set需要更新；
		}
		else if ( check == 1 ) {//check=1时表示为交换两个数的第二个数，选择前插在set之前，也就是pre之后；
			go->next = set;//前置:go指向set；
			if ( pre == set ) {
				set->next = NULL;//如果是第一个节点，特殊初始化set的next为NULL；
				back = go;//第一个节点更新back;
			}
			else {
				pre->next = go;//非第一节点下，pre指向go，第一节点的话构成环；
			}
			check = 0;
			pre = go;
			//该情况set不需更新；
		}
	}
	return back;
}
int main () {
	SList test;
	SLInit (&test);
	SLPushFront (&test , 5);
	SLPushFront (&test , 4);
	SLPushFront (&test , 3);
	SLPushFront (&test , 2);
	SLPushFront (&test , 1);
	SLPushFront (&test , 0);
	SLNode* back = swapPairs (&test);
	system ("pause");
	return 0;
}