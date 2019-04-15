#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


typedef int QDataType;

// 链式结构：表示队列 
typedef struct QListNode {
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue {
	QNode* _front;
	QNode* _rear;
	size_t size;
}Queue;

// 初始化队列 
void QueueInit (Queue* q){
	q->_front = NULL;
	q->_rear = NULL;
	q->size = 0;
}

// 队尾入队列 
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

// 队头出队列 
void QueuePop (Queue* q) {
	assert (q);
	QNode* get = q->_front->_pNext;
	free (q->_front);
	q->_front = get;
	q->size--;
}

// 获取队列头部元素 
QDataType QueueFront (Queue* q) {
	return q->_front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack (Queue* q) {
	return q->_rear->_data;
}
// 获取队列中有效元素个数 
int QueueSize (Queue* q) {
	return (int)q->size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty (Queue* q) {
	return !q->size;
}
// 销毁队列 
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