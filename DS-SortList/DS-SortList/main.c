
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

struct SLNode* Merge (struct SLNode* left , struct SLNode*right) {//这就是两个有序链表的合并
	struct SLNode* new = NULL;
	struct SLNode* back = NULL;
	while ( left&&right ) {
		if ( left->value <= right->value ) {
			if ( new == NULL ) {
				new = left;
				back = new;
			}
			else {
				new->next = left;
				new = new->next;
			}
			left = left->next;
		}
		else {
			if ( new == NULL ) {
				new = right;
				back = new;
			}
			else {
				new->next = right;
				new = new->next;
			}
			right = right->next;
		}
	}
	if ( left ) {
		new->next = left;
	}
	else {
		new->next = right;
	}
	return back;
}

struct SLNode* MergeList (struct SLNode*start) {
	if ( !start->next ) { return start; }
	struct SLNode* mid = start , *right = start , *pre = NULL;
	while ( mid&&right ) {//
		right = right->next;
		if ( right ) {
			pre = mid;
			mid = mid->next;
			right = right->next;
		}
	}
	pre->next = NULL;//将mid前的节点next置空，这样就可以停下；
	struct SLNode*l = MergeList (start);
	struct SLNode*r = MergeList (mid);//二叉前序遍历；
	return Merge (l , r);
}

struct SLNode* sortList (struct SLNode* head) {//题的要求不就是让我用堆排序么？,原来不是是并归排序；
	if ( (!head) || (!head->next) ) {
		return head;
	}
	return MergeList (head);
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
	SLNode* back = sortList (test.first);
	system ("pause");
	return 0;
}
