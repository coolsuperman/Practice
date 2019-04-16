#define _CRT_SECURE_NO_WARNINGS 1
#include"all.h"

void ASSERT (Stack*ps) {
	assert (ps);
	assert (ps->_array);
}
// 初始化栈 
void StackInit (Stack* ps) {
	assert (ps);
	ps->_array = (SDataType*)malloc (sizeof (SDataType)*ps->_capacity);
	ps->_top = 0;
}

static void JudgeFull (Stack* ps) {
	if ( ps->_top == ps->_capacity ) {
		SDataType* newl = (SDataType*)malloc (sizeof (SDataType)*(ps->_capacity*2+1));\
			if ( newl ) {
				memcpy (newl , ps->_array , sizeof (SDataType)*ps->_top);
				free (ps->_array);
				ps->_array = newl;
				ps->_capacity = ps->_capacity * 2 + 1;
			}
			else {
				printf ("Malloc space failed!");
			}
	}
}

// 入栈 
void StackPush (Stack* ps , SDataType data) {
	ASSERT (ps);
	JudgeFull (ps);
	ps->_array [ps->_top] = data;
	ps->_top++;
}
// 出栈 
void StackPop (Stack* ps) {
	ASSERT (ps);
	ps->_top--;
}

// 获取栈顶元素 
SDataType StackTop (Stack* ps) {
	ASSERT (ps);
	return ps->_array [ps->_top - 1];
}

// 获取栈中有效元素个数 
int StackSize (Stack* ps) {
	ASSERT (ps);
	return ps->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty (Stack* ps) {
	return !(ps->_top);
}
// 销毁栈 
void StackDestroy (Stack* ps) {
	ASSERT (ps);
	free (ps->_array);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
