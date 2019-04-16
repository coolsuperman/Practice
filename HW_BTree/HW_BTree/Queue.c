#define _CRT_SECURE_NO_WARNINGS 1
#include"all.h"




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

