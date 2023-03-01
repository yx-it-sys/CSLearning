#include<stdio.h>
#include<stdbool.h>
#include<Windows.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct {
	int* elem;
	int length;
	int listsize;
}SqList;

bool INIT_Sq(SqList* L) {
		L->elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
		if (!(L->elem)) exit (1);
		L->length = 5;
		L->listsize = LIST_INIT_SIZE;
		
		return true;
	}

//²åÈëÔªËØ
bool ListInsert_Sq(SqList* L, int i, int e)
{
	if (i<1 || i>L->length + 1) return 2;
	if (L->length >= L->listsize) {
		int* newbase;
		newbase = (int*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(int));
		if (!newbase) exit(3);
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	int* q = &(L->elem[i - 1]);
	
	for (int* p = &(L->elem[(L->length) - 1]); p >= q; --p) {
		*(p +1) = *p;
	}
	*q = e;
	++L->length;
	return true;
}

//É¾³ıÔªËØ
int ListDelete_Sq(SqList* L, int i)
{
	if (i<1 || i>L->length) {
		return 2;
	}
	int* p = &(L->elem[i - 1]);
	int e = *p;
	int* q = (L->elem) + (L->length) - 1;
	for (++p; p <= q; p++) {
		*(p - 1) = *p;
	}
	--(L->length);
	return e;
}
int main()
{
	SqList t,*L;
	L = &t;
	
	INIT_Sq(L);
	for (int i = 0; i < 5; i++) {
		*(t.elem + i) = i + 1;
		printf("%d\n", *(t.elem + i));
	}

	ListInsert_Sq(L, 3, 6);
	for (int i = 0; i < 6; i++) {
		printf("\n%d\n", *(t.elem + i));
	}

	ListDelete_Sq(L, 3);
	for (int i = 0; i < 5; i++) {
		printf("\n%d\n", *(t.elem + i));
	}

	return 0;
}