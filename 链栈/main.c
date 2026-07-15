#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//链栈的定义
typedef struct Linknode {
    int data; //数据域
    struct Linknode *next; //指针域
}LiStack; //栈类型定义

//链栈的初始化
bool InitStack(LiStack *s) {
    if (s == NULL) {
        return false;
    }
    s->next = NULL;
    return true;
}

//判断栈空
bool StackEmpty(LiStack *s) {
    if (s->next == NULL) {
        return true;
    }else {
        return false;
    }
}

//压栈操作
bool Push(LiStack *s, int x) {
    LiStack *P = (LiStack *)malloc(sizeof(LiStack));
    if (P == NULL) {
        return false;
    }
    P->data = x;
    P->next = s->next;
    s->next = P;
    return true;
}

//出栈操作
bool Pop(LiStack *s, int *x) {
    if (s == NULL) {
        return false;
    }
    if (s->next == NULL) {
        return false;
    }
    LiStack *p = s->next;
    *x = p->data;
    s->next = p->next;
    free(p);
    return true;
}

//读取栈顶元素
bool GetTop(LiStack *s, int *x) {
    if (s == NULL) {
        return false;
    }
    if (s->next == NULL) {
        return false;
    }
    *x = s->next->data;
    return true;
}

//销毁栈
bool DestroyStack(LiStack *s) {
    if (s == NULL) {
        return false;
    }
    LiStack *p = s->next;
    while (p != NULL) {
        LiStack *q = p->next;
        free(p);
        p = q;
    }
    s->next = NULL;
    return true;
}

int main(void) {
    LiStack s;
    InitStack(&s);
    return 0;
}
