#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int value;
	struct Node*next;
}Node;
typedef struct Queue {
	Node*front;//记录队列头；
	Node*end;//记录队列尾；
	int size;
}Queue;

void QueueInit(Queue*queue) {
	queue->front = NULL;
	queue->end = NULL;
	queue->size = 0;
}

void QueueDestory(Queue*queue) {
	Node*node, *next;
	for (node = queue->front; node != NULL; node = next) {
		next = node->next;
		free(node);
	}
	queue->front = queue->end = NULL;
	queue->size = 0;
}

void QueuePush(Queue*queue, int val) {
	Node*node = (Node*)malloc(sizeof(Node));
	node->value = val;
	node->next = NULL;
	queue->size++;
	if (queue->end != NULL)
	{
		queue->end->next = node;
		queue->end = node;
	}
	else
	{
		queue->front = queue->end = node;
	}
}

void QueuePop(Queue*queue) {
	assert(queue->size>0);
	queue->size--;
	Node*get = queue->front;
	queue->front = get->next;
	free(get);
	if (queue->front == NULL) {
		queue->end = NULL;
	}//处理只有一个节点的情况；
}

int QueueEnd(const Queue*queue) {
	return queue->end->value;
}

int QueueEmpty(const Queue*queue) {
	return queue->size != 0 ? 0 : 1;
}

typedef struct {
	Queue queue;
	int maxSize;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
	MyStack *stack = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&(stack->queue));
	stack->maxSize = maxSize;
	return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	QueuePush(&(obj->queue), x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int size = obj->queue.size;
	for (int i = 0; i<size - 1; i++) {
		int val = obj->queue.front->value;
		QueuePop(&(obj->queue));
		QueuePush(&(obj->queue), val);
	}
	int val = obj->queue.front->value;
	QueuePop(&(obj->queue));
	return val;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	int size = obj->queue.size;
	for (int i = 0; i<size - 1; i++) {
		int val = obj->queue.front->value;
		QueuePop(&(obj->queue));
		QueuePush(&(obj->queue), val);
	}
	int val = obj->queue.front->value;
	QueuePop(&(obj->queue));
	QueuePush(&(obj->queue), val);
	return val;
}

/** Returns whether the stack is empty. */
int myStackEmpty(MyStack* obj) {
	return QueueEmpty(&(obj->queue));
}

void myStackFree(MyStack* obj) {
	QueueDestory(&(obj->queue));
	free(obj);
}
