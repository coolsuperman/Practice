#define _CRT_SECURE_NO_WARNINGS 1
#include"all.h"

Result _CreateBinTree (BTDataType* array , int size) {
	Result result;
	if ( size == 0 ) {
		result.used = 0;
		result.root = NULL;
		return result;
	}
	if ( array[0]== '#' ) {
		result.used = 1;
		result.root = NULL;
		return result;
	}
	BTNode* root = (BTNode*)malloc (sizeof (BTNode));
	root->_data = array [0];
	Result Left = _CreateBinTree (array + 1 , size - 1);
	Result Right = _CreateBinTree (array + Left.used + 1 , size - 1 - Left.used);
	root->_pLeft = Left.root;
	root->_pRight = Right.root;
	result.used = Left.used + Right.used+1;
	result.root = root;
	return result;
}

// 1. ���������� 
BTNode* CreateBinTree (BTDataType* array , int size) {
	Result result = _CreateBinTree (array , size);
	return result.root;
}


// ���������� 
BTNode* CopyBinTree (BTNode* pRoot) {
	if ( !pRoot ) {
		return NULL;
	}
	BTNode* root = (BTNode*)malloc (sizeof (BTNode));
	root->_data = pRoot->_data;
	root->_pLeft = CopyBinTree (pRoot->_pLeft);
	root->_pRight = CopyBinTree (pRoot->_pRight);
	return root;
}

// ���ٶ����� 
void DestroyBinTree (BTNode* pRoot) {
	if ( !pRoot ) {
		return;
	}
	BTNode* get = pRoot;
	DestroyBinTree (get->_pLeft);
	DestroyBinTree (get->_pRight);
	free (pRoot);
}
// �����������ֱ�����ʽ 
void PreOrder (BTNode* pRoot) {
	if ( !pRoot ) {
		return;
	}
	printf ("%c" , pRoot->_data);
	PreOrder (pRoot->_pLeft);
	PreOrder (pRoot->_pRight);
	return;
}

void InOrder (BTNode* pRoot) {
	if ( !pRoot ) {
		return;
	}
	InOrder (pRoot->_pLeft);
	printf ("%c" , pRoot->_data);
	InOrder (pRoot->_pRight);
	return;
}

void PostOrder (BTNode* pRoot) {
	if ( !pRoot ) {
		return;
	}
	PostOrder (pRoot->_pLeft);
	PostOrder (pRoot->_pRight);
	printf ("%c" , pRoot->_data);
	return;
}
void PreOrderNor (BTNode* pRoot) {
	BTNode *cur = pRoot;
	Stack st;
	st._capacity = 0;//��ʼ��Stack
	StackInit (&st);//
	while ( (!StackEmpty (&st)) || cur != NULL ) {
		while ( cur != NULL ) {//��һ�η��ʽڵ�:cur;
			printf ("%c" , cur->_data);//ǰ��
			StackPush (&st , cur);
			cur = cur->_pLeft;
		}
		BTNode*top = StackTop (&st);//�ڶ��Σ�
		StackPop (&st);
		cur = top->_pRight;
	}
}
void InOrderNor (BTNode* pRoot) {
	BTNode *cur = pRoot;
	Stack st;
	st._capacity = 0;
	StackInit (&st);
	while ( (!StackEmpty (&st)) || cur != NULL ) {
		while ( cur != NULL ) {//��һ�η��ʽڵ�:cur;
			StackPush (&st , cur);
			cur = cur->_pLeft;
		}
		BTNode*top = StackTop (&st);//�ڶ��Σ�
		StackPop (&st);
		printf ("%c" , top->_data);//����
		cur = top->_pRight;
	}
}
void PostOrderNor (BTNode* pRoot) {
	BTNode *cur = pRoot;
	BTNode* last = NULL;
	Stack st;
	st._capacity = 0;
	StackInit (&st);
	while ( (!StackEmpty (&st)) || cur != NULL ) {
		while ( cur != NULL ) {//��һ�η��ʽڵ�:cur;
			StackPush (&st , cur);
			cur = cur->_pLeft;
		}
		BTNode*top = StackTop (&st);//�ڶ��Σ�
		if ( top->_pRight == NULL ) {//�ýڵ�����������ֱ�Ӵ�ӡ��
			printf ("%c" , top->_data);
			StackPop (&st);
			last = top;
		}
		else if ( top->_pRight == last ) {//���ұ߻����Ŀ���ֱ�Ӵ�ӡ�ˣ�
			printf ("%c" , top->_data);
			StackPop (&st);
			last = top;//c=���ζ����ꣻ
		}
		else//������ģ�Ҫִ��������
		cur = top->_pRight;
	}
}
void LevelOrder (BTNode* pRoot) {
	if ( !pRoot ) {
		return;
	}
	Queue queue;
	QueueInit (&queue);
	QueuePush (&queue , pRoot);
	while ( !QueueEmpty (&queue) ) {
		BTNode* front = QueueFront (&queue);
		printf ("%c" , front->_data);
		QueuePop (&queue);
		if ( front->_pLeft ) {
			QueuePush (&queue , front->_pLeft);
		}
		if ( front->_pRight) {
			QueuePush (&queue , front->_pRight);
		}
	}
}

// ��������ĸ߶� 
int Height (BTNode* pRoot) {
	if ( !pRoot ) {
		return 0;
	}
	int left = Height (pRoot->_pLeft);
	int right = Height (pRoot->_pRight);
	return 1 + (left > right ? left : right);
}

// ��ȡ��������K��ڵ�ĸ��� 
int GetKLevelNodeCount (BTNode* pRoot , int K) {
	if ( (!pRoot) || (!K) ) {
		return 0;
	}
	if ( K == 1 ) {
		return 1;
	}
	int leftchild = GetKLevelNodeCount (pRoot->_pLeft , K - 1);
	int rightchild = GetKLevelNodeCount (pRoot->_pRight , K - 1);
	return leftchild + rightchild;
}

// ��ȡ��������Ҷ�ӽڵ�ĸ��� 
int GetLeafNodeCount (BTNode* pRoot) {
	if ( !pRoot ) {
		return 0;
	}
	int back = 0;
	if ( (!pRoot->_pLeft) && (!pRoot->_pRight) )
		back = 1;
	return back+ GetNodeCount (pRoot->_pLeft) + GetNodeCount (pRoot->_pRight);
}

// ��ȡ��������ĳ���ڵ��˫�׽ڵ� 
BTNode* GetNodeParent (BTNode* pRoot , BTNode* pNode) {
	if ( !pRoot ) {
		return NULL;
	}
	assert (pRoot != pNode);
	if ( pRoot->_pLeft == pNode || pRoot->_pRight == pNode ) {
		return pRoot;
	}
	BTNode* left = GetNodeParent (pRoot->_pLeft , pNode);
	if ( left ) {
		return left;
	}
	BTNode* right = GetNodeParent (pRoot->_pRight , pNode);
	return right;
}

// ��ȡ�������нڵ�ĸ��� 
int GetNodeCount (BTNode* pRoot) {
	if ( !pRoot ) {
		return 0;
	}
	return 1 + GetNodeCount (pRoot->_pLeft) + GetNodeCount (pRoot->_pRight);
}

// ��������ľ��� 
BTNode* Mirror (BTNode* pRoot) {
	if ( !pRoot ) {
		return NULL;
	}
	BTNode* root = (BTNode*)malloc (sizeof (BTNode));
	root->_data = pRoot->_data;
	root->_pLeft = CopyBinTree (pRoot->_pRight);
	root->_pRight = CopyBinTree (pRoot->_pLeft);
	return root;
}

// ���������Ƿ�ƽ��O(N^2) 
int get_height (struct BTNode*root) {
	if ( root == NULL ) {
		return 0;
	}
	int left = get_height (root->_pLeft);
	int right = get_height (root->_pRight);
	return (left>right ? left : right) + 1;
}

int IsBalanceTree (BTNode* pRoot) {
	if ( pRoot == NULL ) {
		return 1;
	}
	if ( !IsBalanceTree (pRoot->_pLeft) ) {
		return 0;
	}
	if ( !IsBalanceTree (pRoot->_pRight) ) {
		return 0;
	}
	int diff = get_height (pRoot->_pLeft) - get_height (pRoot->_pRight);
	if ( diff >= -1 && diff <= 1 ) {
		return 1;
	}
	else {
		return 0;
	}
}
