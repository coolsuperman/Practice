#define _CRT_SECURE_NO_WARNINGS 1
//touch new
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef int DataType;
typedef struct SeqList {
	DataType* _array; // 保存顺序表中有效元素个数 
	int _capacity; // 空间总大小 
	int _size; // 有效元素个数 
}SeqList , *PSeqList;

void ASSERT (PSeqList ps) {
	assert (ps);
	assert (ps->_array);
}

void SeqListInit (PSeqList ps) {
	assert (ps);
	ps->_array = (DataType*)malloc (sizeof (DataType)*ps->_capacity);
	ps->_size = 0;
}
void SeqListDestroy (PSeqList ps) {
	ASSERT (ps);
	free (ps->_array);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}

void JudgeFull (PSeqList ps) {
	if ( ps->_size == ps->_capacity ) {
		DataType*back = (DataType*)malloc (sizeof (DataType)*(ps->_capacity * 2 + 1));
		if ( back ) {
			memcpy (back,ps->_array,sizeof(DataType)*ps->_size);
			free (ps->_array);
			ps->_array = back;
			ps->_capacity = ps->_capacity * 2 + 1;
		}
		else {
			printf ("malloc space failed!");
			exit (1);
		}
	}
}

// 任意位置插入 
void SeqListInsert (PSeqList ps , int pos , DataType data) {
	ASSERT (ps);
	assert (pos >= 0 && pos <= ps->_size);
	JudgeFull (ps);
	for ( int i = ps->_size - 1; i >= pos; i-- ) {
		ps->_array [i + 1] = ps->_array [i];
	}
	ps->_array [pos] = data;
	ps->_size++;
}

// 尾插 
void SeqListPushBack (PSeqList ps , DataType data) {
	SeqListInsert (ps , ps->_size , data);
}

// 头插 
void SeqListPushFront (PSeqList ps , DataType data) {
	SeqListInsert (ps , 0 , data);;
}

// 任意位置删除 
void SeqListErase (PSeqList ps , int pos) {
	assert (pos >= 0 && pos < ps->_size);
	ASSERT (ps);
	for ( int i = pos; i < ps->_size; i++ ) {
		ps->_array [i] = ps->_array [i + 1];
	}
	ps->_size--;
}
// 头删 
void SeqListPopFront (PSeqList ps) {
	SeqListErase (ps , 0);
}

// 尾删 
void SeqListPopBack (PSeqList ps) {
	SeqListErase (ps , ps->_size-1);
}

// 检测data是否在顺序表中 
int SeqListFind (PSeqList ps , DataType data) {
	ASSERT (ps);
	int inbox = ps->_size-1;
	while ( inbox>=0 ) {
		if ( ps->_array [inbox] == data ) {
			return 1;
		}
		inbox--;
	}
	return 0;
}

// 移除顺序表中第一个值为data的元素 
void SeqListRemove (PSeqList ps , DataType data) {
	for (int i = 0; i < ps->_size; i++ ) {
		if ( ps->_array [i] == data ) {
			SeqListErase (ps , i);
			break;
		}
	}
}

// 移除顺序表中所有值为data的元素 
void SeqListRemoveAll (PSeqList ps , DataType data) {
	int i = 0;
	while( i < ps->_size ) {
		if ( ps->_array [i] == data ) {
			SeqListErase (ps , i);
		}
		else {
			i++;
		}
	}
}

// 获取顺序表有效元素个数 
int SeqListSize (PSeqList ps) {
	return ps->_size;
}

// 获取顺序表的容量 
int SeqListCapacity (PSeqList ps) {
	return ps->_capacity;
}

// 检测顺序表是否为空 
int SeqListEmpty (PSeqList ps) {
	return !(ps->_size);
}
// 获取顺序表中第一个元素 
DataType SeqListFront (PSeqList ps) {
	return ps->_array [0];
}
// 获取顺序表中最后一个元素 
DataType SeqListBack (PSeqList ps) {
	return ps->_array [ps->_size - 1];
}


int main () {
	SeqList a;
	a._capacity = 3;
	SeqListInit (&a);
	SeqListPushBack (&a,1);
	SeqListPushBack (&a , 2);
	SeqListPushBack (&a , 3);
	SeqListPushBack (&a ,3);
	SeqListPushBack (&a , 5);
	SeqListPushBack (&a , 6);
	printf ("%d\n" , SeqListSize (&a));
	SeqListPopBack (&a);
	SeqListRemoveAll (&a , 3);
	printf ("%d\n" , SeqListSize (&a));
	system ("pause");
	return 0;
}