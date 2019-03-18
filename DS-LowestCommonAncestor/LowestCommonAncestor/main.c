#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

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

int judgeinsert (TreeNode* root , TreeNode* target) {
	if ( !root ) { return 0; }
	if ( root == target ) {
		return 1;
	}
	int left = judgeinsert (root->left , target);
	if ( left ) { return 1; }
	return judgeinsert (root->right , target);
}

TreeNode* lowestCommonAncestor (TreeNode* root , TreeNode* p , TreeNode* q) {
	if ( root == NULL ) { return NULL; }
	if ( q == root || p == root ) {
		return root;
	}
	int qleft = judgeinsert (root->left , q);
	int pleft = judgeinsert (root->left , p);
	if ( (pleft && !qleft) || (qleft && !pleft) || (!pleft&&qleft) || (!qleft&&pleft) ) {
		return root;
	}
	if ( pleft ) {
		return lowestCommonAncestor (root->left , p , q);
	}
	else {
		return lowestCommonAncestor (root->right , p , q);
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
	printf ("%d" , lowestCommonAncestor (&root , root.left->left , root.left->right)->val);
	system ("pause");
	return 0;
}