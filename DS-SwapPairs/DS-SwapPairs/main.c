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

 SLNode* swapPairs (struct SList* head) {//ǰ���巨
	SLNode*back , *set = head->first , *go , *pre = head->first , *next = NULL;//set��back��������һ����pre��back��ǰһ����next�洢go��next
	if ( !head->first ) { return NULL; }
	back = set;//������������׽ڵ���set��
	int check = 1;//��Ϊset�ӵڶ����ڵ㿪ʼ���Գ�ʼ����1��
	for ( go = head->first->next; go != NULL; go = next ) {
		next = go->next;
		if ( check == 0 ) {//check=0ʱ��ʾΪ�����������ĵ�һ������ѡ��β����set����
			go->next = NULL;
			set->next = go;
			check = 1;
			pre = set;
			set = set->next;//�������pre��set��Ҫ���£�
		}
		else if ( check == 1 ) {//check=1ʱ��ʾΪ�����������ĵڶ�������ѡ��ǰ����set֮ǰ��Ҳ����pre֮��
			go->next = set;//ǰ��:goָ��set��
			if ( pre == set ) {
				set->next = NULL;//����ǵ�һ���ڵ㣬�����ʼ��set��nextΪNULL��
				back = go;//��һ���ڵ����back;
			}
			else {
				pre->next = go;//�ǵ�һ�ڵ��£�preָ��go����һ�ڵ�Ļ����ɻ���
			}
			check = 0;
			pre = go;
			//�����set������£�
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