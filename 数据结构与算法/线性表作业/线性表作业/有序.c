/*要求编写一函数 InsertX_B(SqList &L, int x)，将x插入到有序表L中，保持有序性质不变*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<Windows.h>
#define LISTINCREMENT 10
#define LIST_INIT_SIZE 100

typedef struct SqList
{
	int* elem;
	int length;
	int listsize;
}SqList;
bool InitList_Sq(SqList* L)
{
	L->elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return true;
}
bool InsertX_B(SqList* L, int x)
{

	if (L->length >= L->listsize)
	{
		int* newbase = (int*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(int));

		if (!newbase) {
			exit(-1);
		}
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	
	int i ;
	for (i = 0; (L->elem[i] < x) && (i<L->length); i++);
	int* p = L->elem+i;
	int* q = L->elem+(L->length - 1);
	for (q; q >= p; q--) {
		*(q + 1) = *q;
	}
	L->elem[ i ] = x;
	L->length++;
	return true;
}
/*用类C语言设计算法实现顺序表的就地逆置*/
bool Inverse_Sq(SqList* L)
{
	int t = 0;
	for (int i = 0; i < (L->length)/2; i++) {
		t = L->elem[i];
		L->elem[i] = L->elem[L->length - 1 - i];
		L->elem[L->length - 1 - i] = t;
	}
	return true;
}
int main()
{
	SqList list;
	SqList* L = &list;
	InitList_Sq(L);
	L->length = 7;
	for (int i = 0; i < L->length; i++)
	{
		scanf("%d", list.elem+i);
	}
	for (int i = 0; i < list.length; i++)
		printf("%d\t", list.elem[i]);

	printf("\n");

	InsertX_B(L, 7);
	for (int i = 0; i < list.length; i++)
		printf("%d\t", list.elem[i]);
	printf("\n");
	Inverse_Sq(L);
	for (int i = 0; i < list.length; i++)
		printf("%d\t", list.elem[i]);
	return 0;

}