#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//双链表----双链表的定义
typedef struct DNode { //定义双链表结点类型
    int data; //数据域
    struct DNode *prior,*next; //前驱和后继指针
}DNode,*DLinklist;

//初始化双链表
bool InitLinkList(DLinklist *L) {
    *L = (DLinklist)malloc(sizeof(DNode)); //分配一个头结点
    if (*L == NULL) { //内存不足,分配失败
        return false;
    }
    (*L) -> prior = NULL; //头结点prior永远指向NULL
    (*L) -> next = NULL; //头结点之后暂时还没有结点
    return true;
}

//判断双链表是否为空 (带头结点)
bool isEmpty(DLinklist L) {
    if (L -> next == NULL) {
        return true;
    }else {
        return false;
    }
}

bool InsertNextDNode (DNode *p,DNode *s) { //只是插入函数,要手动创建新结点开辟内存,存入数据e
    if (p == NULL || s == NULL) {
        return false;
    }
    s -> next = p -> next;
    if (p -> next != NULL) {
        p -> next -> prior = s;
    }
    s -> prior = p;
    p -> next = s;
    return true;
}

//删除p的后继结点q结点
bool DeleteNextDNode(DNode *p) {
    if (p == NULL) {
        return false;
    }
    DNode *q = p -> next;
    if (q == NULL) {
        return false;
    }
    p -> next = q -> next;
    if (p -> next != NULL) {
        q -> next -> prior = p;
    }
    free(q);
    return true;
}

void DestroyList(DLinklist L) {
    while (L -> next != NULL) { //循环释放各个数据结点
        DeleteNextDNode(L);
    }
    free (L); //释放头结点
    L = NULL; //头指针指向NULL
}

void printList(DLinklist L) {
    if (isEmpty(L)) {
        printf("List is empty\n");
        return;
    }
    DNode *p = L -> next;
    while (p != NULL) {
        printf("%d ",p -> data);
        p = p -> next;
    }
}

int main(void) {
    DLinklist L;
    InitLinkList(&L);
    int num;
    printf("Enter number of nodes: ");
    scanf("%d",&num);
    DNode *tail = L;
    for (int i=0;i<num;i++) {
        int val;
        printf("Enter value of node %d: ",i+1);
        scanf("%d",&val);
        DNode *s = (DNode *)malloc(sizeof(DNode));
        s -> data = val;
        s -> prior = NULL;
        s -> next = NULL;
        InsertNextDNode(tail,s);
        tail = s;
    }
    printf("List after creation:\n");
    printList(L);
    DestroyList(L);
    return 0;
}