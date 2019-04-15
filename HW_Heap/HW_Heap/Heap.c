#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int DataType;
typedef int (*Judge)(int* , int , int);

typedef struct Heap {
	DataType* _array;
	int _capacity;
	int _size;
}Heap;

int Big (int*arr , int a , int b) {
	return arr [a] > arr [b] ? 1 : 0;
}

int Small (int*arr , int a , int b) {
	return arr [a] < arr [b] ? 1: 0;
}

void swap (int * arr , int a , int b) {
	int tmp = arr [a];
	arr [a] = arr [b];
	arr [b] = tmp;
}

void AdjustDown (Heap*hp ,int root,Judge choose) {
	assert (root<hp->_size);
	int parent = root;
	int child = parent * 2 + 1;//����;
	while ( child < hp->_size ) {
		if ( child + 1 < hp->_size ) {
			if ( !choose (hp->_array, child , child + 1) ) {
				child = child + 1;
			}
		}
		if ( choose (hp->_array, parent , child) ) {
			break;
		}
		swap (hp->_array, parent , child);
		parent = child;
		child = parent * 2 + 1;
	}
}

void AdjustUp (Heap*hp , Judge choose) {
	int child = hp->_size - 1;
	int parent = (child - 1) / 2;
	while ( parent >= 0 ) {
		if ( choose (hp->_array , parent,child) ) {
			break;
		}
		swap (hp->_array , parent , child);
		child = parent;
		if ( !child ) {//���child=0����parent=-1/2=0����һֱ��ѭ�����������⴦��һ��
			break;
		}
		parent = (child - 1) / 2;
	}
}

// ������ 
void CreatHeap (Heap* hp , int* array , int size, Judge choose) {
	hp->_size = size;
	hp->_array = array;
	hp->_capacity = size;
	for ( int i = (hp->_size - 2)/2; i >= 0; i-- ) {//����ʹ�õ���ʽ
		AdjustDown (hp , i , choose);
	}
}

void CheckFull (Heap*hp) {
	if ( hp->_size == hp->_capacity ) {
		DataType* new = (DataType*)malloc (sizeof (DataType)*(hp->_capacity * 2 + 1));
		if ( new ) {
			memcpy (new , hp->_array , sizeof (DataType)*hp->_size);
			free (hp->_array);
			hp->_array = new;
			hp->_capacity = hp->_capacity * 2 + 1;
		}
		else {
			printf ("malloc Failed!");
		}
	}
}
// ����в���ֵΪdata��Ԫ�� 
void InsertHeap (Heap* hp , DataType data,Judge choose) {
	assert (hp);
	if ( !hp->_array ) {
		printf ("Must Creat Heap First\n");
		return;
	}
	CheckFull (hp);
	hp->_array [hp->_size] = data;
	hp->_size++;
	AdjustUp (hp,choose);
}
// ɾ���Ѷ�Ԫ�� 
void EraseHeap (Heap* hp, Judge choose) {
	assert (hp);
	assert (hp->_array);
	swap (hp->_array , 0 , hp->_size - 1);
	hp->_size--;
	AdjustDown (hp,0,choose);
}

// ��ȡ������ЧԪ�ظ��� 
int SizeHeap (Heap* hp) {
	return hp->_size;
}

// �����Ƿ�Ϊ�� 
int EmptyHeap (Heap* hp) {
	return !hp->_size;
}

// ��ȡ�Ѷ�Ԫ�� 
DataType TopHeap (Heap* hp) {
	return hp->_array [0];
}

// ���ٶ� 
void DestroyHeap (Heap* hp) {
	hp->_capacity = 0;
	hp->_size = 0;
	free (hp->_array);
	hp->_array = NULL;
}


int main () {
	int (*p[])(int* , int , int) = { Small , Big };
	int i = 0;
	printf ("0.С�ѣ�1.���\n");
	scanf ("%d" , &i);
	Judge choose = p[i];
	DataType arr[] = { 22 , 44 , 63 , 20 , 76 , 35 , 99 , 10 , 32 , 25 , 33 , 65 , 34 };
	int size = sizeof (arr) / sizeof (arr [0]);
	Heap test;
	CreatHeap (&test,arr,size,choose);
	printf ("%d---%d\n" , TopHeap (&test),SizeHeap(&test));
	EraseHeap (&test, choose);
	printf ("%d---%d\n" , TopHeap (&test) , SizeHeap (&test));
	EraseHeap (&test , choose);
	printf ("%d---%d\n" , TopHeap (&test) , SizeHeap (&test));
	InsertHeap (&test , 1 , choose);
	printf ("%d---%d\n" , TopHeap (&test) , SizeHeap (&test));
	system ("pause");
	return 0;
}