#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//链式队列的定义
typedef struct LNode {
    int data;
    struct LNode *next;
}LNode;
typedef struct {
    LNode *front,*rear;
    int length;
}LinkQueue;

//初始化队列
bool InitQueue(LinkQueue *Q) {
    Q->front = Q->rear = (LNode *)malloc(sizeof(LNode));
    Q->front->next = NULL;
    int length = 0;
}

//队列判空
bool isEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) {
        return true;
    }else {
        return false;
    }
}

//入队操作
bool EnQueue(LinkQueue *Q, int x) {
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) {
        return false;
    }
    s->data = x;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    Q->length++;
    return true;
}

//出队操作
bool DeQueue(LinkQueue *Q, int *x) {
    if (isEmpty(*Q)) {
        return false;
    }
    LNode *p = Q->front->next;
    *x = p->data; //用x返回队头元素
    Q->front->next = p->next; //修改头结点的next指针
    if (Q->rear==p) { //此次是最后一个结点入队
        Q->rear = Q->front; //修改rear指针
    }
    free(p); //释放结点空间
    Q->length--;
    return true;
}

int main(void) {
    LinkQueue Q;
    InitQueue(&Q);
    return 0;
}
