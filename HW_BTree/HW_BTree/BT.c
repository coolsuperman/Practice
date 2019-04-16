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

// 1. 创建二叉树 
BTNode* CreateBinTree (BTDataType* array , int size) {
	Result result = _CreateBinTree (array , size);
	return result.root;
}


// 拷贝二叉树 
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

// 销毁二叉树 
void DestroyBinTree (BTNode* pRoot) {
	if ( !pRoot ) {
		return;
	}
	BTNode* get = pRoot;
	DestroyBinTree (get->_pLeft);
	DestroyBinTree (get->_pRight);
	free (pRoot);
}
// 二叉树的三种遍历方式 
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
	st._capacity = 0;//初始化Stack
	StackInit (&st);//
	while ( (!StackEmpty (&st)) || cur != NULL ) {
		while ( cur != NULL ) {//第一次访问节点:cur;
			printf ("%c" , cur->_data);//前序
			StackPush (&st , cur);
			cur = cur->_pLeft;
		}
		BTNode*top = StackTop (&st);//第二次；
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
		while ( cur != NULL ) {//第一次访问节点:cur;
			StackPush (&st , cur);
			cur = cur->_pLeft;
		}
		BTNode*top = StackTop (&st);//第二次；
		StackPop (&st);
		printf ("%c" , top->_data);//中序
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
		while ( cur != NULL ) {//第一次访问节点:cur;
			StackPush (&st , cur);
			cur = cur->_pLeft;
		}
		BTNode*top = StackTop (&st);//第二次；
		if ( top->_pRight == NULL ) {//该节点无右子树，直接打印跟
			printf ("%c" , top->_data);
			StackPop (&st);
			last = top;
		}
		else if ( top->_pRight == last ) {//从右边回来的可以直接打印了；
			printf ("%c" , top->_data);
			StackPop (&st);
			last = top;//c=三次都已完；
		}
		else//左边来的，要执行向右走
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

// 求二叉树的高度 
int Height (BTNode* pRoot) {
	if ( !pRoot ) {
		return 0;
	}
	int left = Height (pRoot->_pLeft);
	int right = Height (pRoot->_pRight);
	return 1 + (left > right ? left : right);
}

// 获取二叉树第K层节点的个数 
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

// 获取二叉数中叶子节点的个数 
int GetLeafNodeCount (BTNode* pRoot) {
	if ( !pRoot ) {
		return 0;
	}
	int back = 0;
	if ( (!pRoot->_pLeft) && (!pRoot->_pRight) )
		back = 1;
	return back+ GetNodeCount (pRoot->_pLeft) + GetNodeCount (pRoot->_pRight);
}

// 获取二叉树中某个节点的双亲节点 
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

// 获取二叉树中节点的个数 
int GetNodeCount (BTNode* pRoot) {
	if ( !pRoot ) {
		return 0;
	}
	return 1 + GetNodeCount (pRoot->_pLeft) + GetNodeCount (pRoot->_pRight);
}

// 求二叉树的镜像 
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

// 检测二叉树是否平衡O(N^2) 
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
