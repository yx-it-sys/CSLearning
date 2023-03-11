#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#define NULL£°
typedef struct LNode {
    int data;
    struct LNode* next;
}LNode, LinkList;



void Create_L1(LinkList* L, int n)
{
    LinkList* p;
    int i;
    L = (LinkList*)malloc(sizeof(LNode));

    L->next = NULL;
    for (i = n; i > 0; i--) {
        p = (LinkList*)malloc(sizeof(LNode));
        scanf("%d", &(p->data));
        p->next = L->next;
        L->next = p;
    }
}

void reverse_cir(LinkList* h)
{
    LinkList* p = h;
    LinkList* q = h;
    if (h->next == NULL)
        return -1;
    if (h->next->next == NULL)
        return 0;

    p = h->next->next;
    while (p != h) {
        q = p;
        p = p->next;
        q->next = h->next;
        h->next = q;
    }
    
}

int main()
{
    LinkList* re=NULL;
    int n = 5;
    Create_L1(re, 5);
    LinkList* p = re;
    while (re) {
        printf("%d\n", re->data);
        re = re->next;
    }
    return 0;
}