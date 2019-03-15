#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0

char*array;
int treesize;

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

int get_height(TreeNode*root) {
	if (root == NULL) {
		return 0;
	}
	int left = get_height(root->left);
	int right = get_height(root->right);
	return (left>right ? left : right) + 1;
}

void _tree2str(struct TreeNode* t) {
	if (t == NULL) {
		return;
	}
	array[treesize++] = '(';
	int n = sprintf(array + treesize, "%d", t->val);//返回打印个数，打印到array+treesize处
	treesize += n;
	if (t->left == NULL&&t->right != NULL) {
		array[treesize++] = '(';
		array[treesize++] = ')';
	}
	else {
		_tree2str(t->left);
	}
	_tree2str(t->right);
	array[treesize++] = ')';
}
char* tree2str(struct TreeNode* t) {
	if (t == NULL) {
		return "";
	}
	array = (char*)malloc(sizeof(char) * 100 * 10000);
	treesize = 0;
	int n = sprintf(array + treesize, "%d", t->val);
	treesize += n;
	if (t->left == NULL&&t->right != NULL) {
		array[treesize++] = '(';
		array[treesize++] = ')';
	}
	else {
		_tree2str(t->left);
	}
	_tree2str(t->right);
	array[treesize++] = '\0';
	return array;
}
int main() {
	TreeNode root;
	Back* roots_left, *roots, *roots_right;
	int returnSize = 0;
	InitRoot(&root, 1);
	roots = BuyMem(&root, 2, 3);
	roots_left = BuyMem(roots->left, 4, 5);
	roots_right = BuyMem(roots->right, 6, 7);
	char*result = tree2str(&root);
	printf("%s", result);
	system("pause");
	return 0;
}