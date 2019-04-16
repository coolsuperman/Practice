#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef char BTDataType;//二叉树
typedef struct BTNode {
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}BTNode;

typedef BTNode* SDataType ;//栈
typedef struct Stack {
	SDataType* _array;
	int _capacity;
	int _top; // 标记栈顶位置 
}Stack;

typedef BTNode* QDataType ;// 队列 
typedef struct QListNode {
	struct QListNode* _pNext;
	QDataType _data;
}QNode;
typedef struct Queue {//// 队列的结构 
	QNode* _front;
	QNode* _rear;
	size_t size;
}Queue;


typedef struct Result {
	int used;
	BTNode* root;
}Result;


void StackInit (Stack* ps);
void StackPush (Stack* ps , SDataType data);
void StackPop (Stack* ps);
SDataType StackTop (Stack* ps);
int StackSize (Stack* ps);
int StackEmpty (Stack* ps);
void StackDestroy (Stack* ps);

void QueueInit (Queue* q);
void QueuePush (Queue* q , QDataType data);
void QueuePop (Queue* q);
QDataType QueueFront (Queue* q);
QDataType QueueBack (Queue* q);
int QueueSize (Queue* q);
int QueueEmpty (Queue* q);
void QueueDestroy (Queue* q);

BTNode* CreateBinTree (BTDataType* array , int size);
BTNode* CopyBinTree (BTNode* pRoot);
void DestroyBinTree (BTNode* pRoot);
void PreOrder (BTNode* pRoot);
void PreOrderNor (BTNode* pRoot);
void InOrder (BTNode* pRoot);
void InOrderNor (BTNode* pRoot);
void PostOrder (BTNode* pRoot);
void PostOrderNor (BTNode* pRoot);
void LevelOrder (BTNode* pRoot);
int GetNodeCount (BTNode* pRoot);
int Height (BTNode* pRoot);
int IsBalanceTree (BTNode* pRoot);
int GetLeafNodeCount (BTNode* pRoot);
int GetKLevelNodeCount (BTNode* pRoot , int K);
BTNode* GetNodeParent (BTNode* pRoot , BTNode* pNode);
BTNode* Mirror (BTNode* pRoot);