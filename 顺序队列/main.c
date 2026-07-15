#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//顺序队列的定义 (也叫循环队列)
#define MaxSize 10 //定义队列中元素的最大个数
typedef struct {
    int data[MaxSize]; //用静态数组存放数据元素
    int front, rear; //队头指针和队尾指针
    int tag; //最近执行的时插入/删除操作
}SqQueue;

//初始化顺序队列
bool InitQueue(SqQueue *Q) {
    if (Q->front == Q->rear) {
        return false;
    }
    Q->front = 0;
    Q->rear = 0;
    return true;
}

//顺序队列判空
bool QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear && Q.tag == 0) {
        return true;
    }else {
        return false;
    }
}

//顺序队列判满
bool QueueFull(SqQueue Q) {
    if (Q.rear == Q.front && Q.tag == 0) {
        return true;
    }
    return false;
}

//入队操作
bool EnQueue(SqQueue *Q, int x) {
    if (QueueEmpty(*Q)) { //空队列则报错
        return false;
    }
    if ((QueueFull(*Q))){ //队满则报错
        return false;
    }
    Q->data[Q->rear] = x; //将x插入队尾
    Q->rear = (Q->rear + 1) % MaxSize; //队尾指针+1取余
    //如果队满时rear指针会重新指向0
    Q->tag = 1;
    return true;
}
//最后形状像一个环形

//出队操作
bool DeQueue(SqQueue *Q, int *x) {
    if (QueueEmpty(*Q)) { //空队列则报错
        return false;
    }
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    Q->tag = 0;
    return true;
}

//获取队头元素的值并用x返回
bool GetHead(SqQueue *Q, int *x) {
    if (Q->front == Q->rear) {
        return false;
    }
    *x = Q->data[Q->front];
    return true;
}



int main(void) {
    SqQueue Q;
    InitQueue(&Q);

    return 0;
}
