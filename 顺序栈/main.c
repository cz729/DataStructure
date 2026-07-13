#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//顺序栈的定义
#define MaxSize 10 //定义栈中元素的最大个数
typedef struct {
    int data[MaxSize]; //静态数组存放栈中元素
    int top; //栈顶指针
}SqStack;

//初始化栈
void initSqStack(SqStack *s) {
    s -> top = -1;  //初始化栈顶指针
}

//判断栈空
bool StackEmpty(SqStack s) {
    if (s.top == -1) { //栈空
        return true;
    }else { //不空
        return false;
    }
}

//压栈操作
bool push(SqStack *s, int x) {
    if (s -> top == MaxSize - 1) { //栈满,报错
        return false;
    }
    s -> top = s -> top + 1; //指针先加1
    s -> data[s -> top] = x; //新元素入栈
    //上面两行等价于 s -> data[++s -> top] = x;
    return true;
}

//出栈操作
bool pop(SqStack *s, int *x) {
    if (s -> top == -1) { //栈空,报错
        return false;
    }
    *x = s -> data[s -> top]; //栈顶元素先出栈
    s -> top = s -> top - 1; //指针再减1
    //上面两行等价于 x = s -> data[s -> top--]
    return true;
}

//读栈顶元素
bool GetTop(SqStack s, int *x) {
    if (s.top == -1) { //栈空,报错
        return false;
    }
    *x = s.data[s.top]; //x记录栈顶元素
    return true;
}

int main(void) {
    SqStack s; //声明一个顺序栈(分配空间)
    return 0;
}
