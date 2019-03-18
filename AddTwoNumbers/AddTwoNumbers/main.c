//�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDatatype;
typedef struct SLNode {
	SLDatatype val;
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
	node->val = value;
	return node;
}

void SLPushFront (SList *list , SLDatatype value) {
	assert (list);
	SLNode* get = SLBuyMem (value);
	get->next = list->first;
	list->first = get;
}

SLNode* addTwoNumbers (struct SList* lfirst , struct SList* lsecond) {
	struct SLNode* l1 = lfirst->first;
	struct SLNode* l2 = lsecond->first;
	struct SLNode* back = l1;
	int next = 0;//��λ��־
	if ( l1 == NULL&&l2 == NULL ) { return NULL; }
	if ( l1 == NULL/*||l1->val==0*/ ) {
		return l2;
	}
	else if ( l2 == NULL/*||l2->val==0*/ ) {
		return l1;
	}
	else {
		while ( l1->next&&l2->next ) {
			l1->val += l2->val + next;
			next = 0;
			if ( l1->val>9 ) {
				next = 1;
				l1->val -= 10;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		l1->val += l2->val + next;
		next = 0;
		if ( l1->val>9 ) {
			next = 1;
			l1->val -= 10;
		}
		if ( l1->next == NULL ) {//��ʡ�ռ�ֱ��ʹ��l1;�����l2
			l1->next = l2->next;
		}
		while ( next&&l1->next ) {//1+99999
			l1 = l1->next;
			l1->val += next;
			next = 0;
			if ( l1->val>9 ) {
				next = 1;
				l1->val -= 10;
			}
		}
		if ( l1->next == NULL&&next ) {//���λ�����Ҫ��λ��
			l1->next = (SLNode*)malloc (sizeof (SLNode));
			l1->next->next = NULL;
			l1->next->val = 1;
			next = 0;
		}
	}
	return back;
}
int main () {
	SList test , test2;
	SLInit (&test);
	SLPushFront (&test , 5);
	SLPushFront (&test , 4);
	SLPushFront (&test , 3);
	SLPushFront (&test , 2);
	SLPushFront (&test , 1);
	SLPushFront (&test , 0);
	SLInit (&test2);
	SLPushFront (&test2 , 5);
	SLPushFront (&test2 , 4);
	SLPushFront (&test2 , 3);
	SLPushFront (&test2 , 2);
	SLPushFront (&test2 , 1);
	SLPushFront (&test2 , 0);
	SLNode* back = addTwoNumbers (&test, &test2);
	while ( back ) {
		printf ("%d" , back->val);
		back = back->next;
	}
	system ("pause");
	return 0;
}