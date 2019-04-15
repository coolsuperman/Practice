#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


typedef int QDataType;

// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode {
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue {
	QNode* _front;
	QNode* _rear;
	size_t size;
}Queue;

// ��ʼ������ 
void QueueInit (Queue* q){
	q->_front = NULL;
	q->_rear = NULL;
	q->size = 0;
}

// ��β����� 
void QueuePush (Queue* q , QDataType data) {
	assert (q);
	QNode*new = (QNode*)malloc (sizeof (QNode));
	new->_data = data;
	new->_pNext = NULL;
	if ( !q->_front ) {
		q->_front = new;
		q->_rear = new;
	}
	else {
		q->_rear->_pNext = new;
		q->_rear = new;
	}
	q->size++;
}

// ��ͷ������ 
void QueuePop (Queue* q) {
	assert (q);
	QNode* get = q->_front->_pNext;
	free (q->_front);
	q->_front = get;
	q->size--;
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront (Queue* q) {
	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack (Queue* q) {
	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize (Queue* q) {
	return (int)q->size;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty (Queue* q) {
	return !q->size;
}
// ���ٶ��� 
void QueueDestroy (Queue* q) {
	QNode* go = q->_front;
	while ( go ) {
		QNode* next = go->_pNext;
		free (go);
		go = next;
	}
	q->_front = NULL;
	q->_rear = NULL;
	q->size = 0;
}

int main () {
	Queue a;
	QueueInit (&a);
	QueuePush (&a , 1);
	QueuePush (&a , 4);
	QueuePush (&a , 3);
	QueuePush (&a , 2);
	printf ("%d\n",QueueSize(&a));
	QueuePop (&a);
	printf ("%d\n" , QueueSize (&a));
	printf ("%d   %d\n" , a._front->_data , a._rear->_data);
	system ("pause");
	return 0;
}