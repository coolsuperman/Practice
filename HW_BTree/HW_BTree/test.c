#define _CRT_SECURE_NO_WARNINGS 1
#include"all.h"

int main () {
	char arr[] ="1248##9##61###37##5##";
	int size = strlen(arr);
	BTNode*root = CreateBinTree (arr , size);
	BTNode*new1 = CopyBinTree ( root);
	PostOrder (root);
	printf ("\n");
	PostOrderNor (root);
	printf ("\n");
	PostOrder (new1);
	printf ("\n");
	LevelOrder (root);
	printf ("\n%d\n" , Height (root));
	printf ("%d\n" , GetNodeCount (root));
	printf ("%d\n",GetKLevelNodeCount (root , 4));
	printf ("%c\n" , GetNodeParent (root , root->_pLeft->_pLeft)->_data);
	system ("pause");
	return 0;
}