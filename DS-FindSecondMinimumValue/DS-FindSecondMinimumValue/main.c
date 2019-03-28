#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
typedef struct TreeNode {
	int val;
	struct TreeNode *left;//左子树的根节点
	struct TreeNode*right;//右子树的根节点；
}TreeNode;

typedef struct Back {
	struct TreeNode *left;//左子树的根节点
	struct TreeNode*right;//右子树的根节点；
}Back;

Back* BuyMem (TreeNode*root , int val_left , int val_right) {
	TreeNode*son_left = (TreeNode*)malloc (sizeof (TreeNode));
	son_left->val = val_left;
	son_left->left = NULL;
	son_left->right = NULL;
	TreeNode*son_right = (TreeNode*)malloc (sizeof (TreeNode));
	son_right->val = val_right;
	son_right->left = NULL;
	son_right->right = NULL;
	root->left = son_left;
	root->right = son_right;
	Back result;
	result.left = son_left;
	result.right = son_right;
	return &result;
}
void InitRoot (TreeNode*root , int val_root) {
	root->val = val_root;
	root->left = NULL;
	root->right = NULL;
}

void fun (struct TreeNode* root , int* a , int* b) {
	if ( !root ) { return; }
	fun (root->left , a , b);
	fun (root->right , a , b);
	if ( *a>root->val ) {
		*b = *a;
		*a = root->val;
	}
	else if ( *a<root->val ) {
		if ( *a == *b || root->val<*b )
			*b = root->val;
	}
}

int findSecondMinimumValue (struct TreeNode* root) {
	if ( !root->left ) {
		return -1;
	}
	else {
		int min = root->val , min_2 = root->val;
		fun (root , &min , &min_2);
		if ( root->val == min_2 ) { return -1; }
		return min_2;
	}
}

int main () {
	TreeNode root;
	Back* roots_left , *roots , *roots_right;
	int returnSize = 0;
	InitRoot (&root , 1);
	roots = BuyMem (&root , 2 , 3);
	roots_left = BuyMem (roots->left , 4 , 5);
	roots_right = BuyMem (roots->right , 6 , 7);
	printf ("%d\n", findSecondMinimumValue (&root));
	system ("pause");
	return 0;
}