#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct {
    int* elem;
    int length;
    int listsize;
}SqList;

int ListSearch(SqList* L, int e)
{
    if (L -> length >= L -> listsize) {
        int* newbase = (int*)realloc(L -> elem,
            (L -> listsize + LISTINCREMENT) * sizeof(int));
        L->elem = newbase;
    }
    

    int* p = &(L->elem[L->length - 1]);
    for (p; p >= L->elem; p--) {
            *(p + 1) = *p;
        }
    L -> elem[0] = e;
    ++L -> length;
    int i;
    for (i = L -> length; L->elem[i] != e; i--);
    return i;
}

bool INIT_Sq(SqList* L) {
    L->elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
    if (!(L->elem)) exit(1);
    L->length = 5;
    L->listsize = LIST_INIT_SIZE;

    return true;
}

int main()
{
    SqList list, * L;
    L = &list;
    INIT_Sq(L);
    for (int i = 0; i <= 5; i++) {
        scanf("%d", list.elem + i);
    }
    for (int i = 0; i <= 5; i++) {
        printf("%d\n", *(list.elem + i));
    }
    printf("%d\n",ListSearch(L, 4));

    return 0;
}