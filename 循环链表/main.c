#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//循环单链表
typedef struct LNode { //定义单链表结点类型
    int data; //每个结点存放一个数据元素
    struct LNode *next; //指针指向下一个结点
}LNode,*LinkList;

//初始化一个循环单链表
bool InitList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(LNode)); //分配一个头结点
    if(*L == NULL) { //内存不足,分配失败
        return false;
    }
    (*L)->next = (*L); //头结点next指向头结点
    return true;
}

//判断循环单链表是否为空
bool EmptyList(LinkList L) {
    if (L->next == L) {
        return true;
    }else {
        return false;
    }
}

//判断结点p是否为循环单链表的表尾结点
bool isTail(LinkList L,LNode *p) {
    if (p -> next == L) {
        return true;
    }else {
        return false;
    }
}

//循环双链表
typedef struct DNode {
    int data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

//初始化一个循环双链表
bool InitDList(DLinkList *L) {
    *L = (DLinkList)malloc(sizeof(DNode));
    if(*L == NULL) {
        return false;
    }
    (*L) -> prior = (*L);
    (*L) -> next = (*L);
    return true;
}

//判断循环双链表是否为空
bool EmptyDList(DLinkList L) {
    if (L -> next == L) {
        return true;
    }else {
        return false;
    }
}

//判断结点p是否为循环双链表的表尾结点
bool isDTail(DLinkList L,DNode *p) {
    if (p -> next == L) {
        return true;
    }else {
        return false;
    }
}

//在p结点之后插入s结点
bool InsertNextDNode(DNode *p,DNode *s) {
    s -> next = p -> next;
    p -> next -> prior = s;
    p -> next = s;
    s -> prior = p;
    return true;

}

//删除p的后继结点q
bool DeleteNextDNode(DNode *p,DNode *q) {
    p -> next = q -> next;
    q -> next ->prior = p;
    free(q);
    return true;
}

int main(void) {

    return 0;
}
