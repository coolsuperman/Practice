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

void gocheck (struct TreeNode*root , int*count , int*val , int k) {
	if ( !root ) { return; }
	gocheck (root->left , count , val , k);
	(*count)++;
	if ( *count == k ) {
		*val = root->val;
		return;
	}
	gocheck (root->right , count , val , k);
}
int kthSmallest (struct TreeNode* root , int k) {
	if ( !root ) {
		return -1;
	}
	int count = 0 , val = 0;
	gocheck (root , &count , &val , k);
	return val;
}
int main () {
	TreeNode root;
	Back* roots_left , *roots , *roots_right;
	int returnSize = 0;
	InitRoot (&root , 1);
	roots = BuyMem (&root , 2 , 3);
	roots_left = BuyMem (roots->left , 4 , 5);
	roots_right = BuyMem (roots->right , 6 , 7);
    printf ("%d\n",kthSmallest (&root , 2));
	system ("pause");
	return 0;
}