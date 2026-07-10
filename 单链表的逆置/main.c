#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode,*LinkList;

LinkList InitList() {
    LinkList L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL) {
        return false;
    }
    (L)->next = NULL;
    return L;
}

LinkList List_TailInsert(LinkList L) {
    int x;
    LNode *s,*r;
    r = L;
    scanf("%d",&x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s -> data = x;
        r -> next = s;
        r = s;
        scanf("%d",&x);
    }
    r -> next = NULL;
    return L;
}

bool ReverseList (LinkList L) {
    if (L == NULL) return false;
    if (L -> next == NULL) {
        return false;
    }
    LNode *p = L -> next;
    LNode *q;
    L -> next = NULL;
    while (p != NULL) {
        q = p -> next;
        p -> next = L -> next;
        L -> next = p;
        p = q;
    }
    return true;
}

void PrintList(LinkList L) {
    if (L == NULL) return;
    LNode *p = L -> next;
    while (p != NULL) {
        printf("%d ", p -> data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    LinkList L;
    L = InitList();
    List_TailInsert(L);
    ReverseList(L);
    PrintList(L);
    return 0;
}