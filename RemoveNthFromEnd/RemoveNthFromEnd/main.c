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

struct SLNode* removeNthFromEnd (struct SList* head1 , int n) {
	SLNode* head = head1->first;
	if ( head->next == NULL ) { return NULL; }
	int count = n;
	struct SLNode* go = head;
	struct SLNode* back = head;
	while ( n-- ) {
		go = go->next;
	}
	if ( go == NULL ) {
		struct SLNode* dele = head;
		back = head->next;
		free (dele);
		return back;
	}
	while ( go->next ) {
		head = head->next;
		go = go->next;
	}
	struct SLNode* dele = head->next;
	head->next = head->next->next;
	free (dele);
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
	SLNode* back = removeNthFromEnd (&test ,3);
	system ("pause");
	return 0;
}