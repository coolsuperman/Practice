#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
typedef struct TreeNode
{
	int val;
	struct TreeNode *left;//左子树的根节点
	struct TreeNode*right;//右子树的根节点；
}TreeNode;

typedef struct Back {
	struct TreeNode *left;//左子树的根节点
	struct TreeNode*right;//右子树的根节点；
}Back;

Back* BuyMem(TreeNode*root, int val_left, int val_right) {
	TreeNode*son_left = (TreeNode*)malloc(sizeof(TreeNode));
	son_left->val = val_left;
	son_left->left = NULL;
	son_left->right = NULL;
	TreeNode*son_right = (TreeNode*)malloc(sizeof(TreeNode));
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
void InitRoot(TreeNode*root, int val_root) {
	root->val = val_root;
	root->left = NULL;
	root->right = NULL;
}

int isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL&&q == NULL) {
		return true;
	}
	if (p == NULL || q == NULL) {
		return false;
	}
	return p->val == q->val&& isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}
int FindNode(struct TreeNode* s, struct TreeNode* target) {
	if (s == NULL) {
		return false;
	}
	if (s->val == target->val&&isSameTree(s, target)) {
		return true;
	}//根
	int get = FindNode(s->left, target);
	if (get) { return get; }//左
	return FindNode(s->right, target);//右
}
int isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (t == NULL) {
		return true;
	}
	return FindNode(s, t);
}

int main() {
	TreeNode root;
	Back* roots_left, *roots, *roots_right;
	int returnSize = 0;
	InitRoot(&root, 1);
	roots = BuyMem(&root, 2, 3);
	roots_left = BuyMem(roots->left, 4, 5);
	roots_right = BuyMem(roots->right, 6, 7);
	if (isSubtree(&root, roots)) {
		printf("is\n");
	}
	else
	{
		printf("not\n");
	}
	system("pause");
	return 0;
}