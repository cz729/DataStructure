#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//栈的定义
#define MaxSize 10
typedef struct {
    char data[MaxSize];
    int top;
}   SqStack;

//初始化栈
bool InitSqStack(SqStack *s) {
    s->top = -1;
}

//判断栈是否为空
bool StackEmpty(SqStack s) {
    if (s.top == -1) {
        return true;
    }else {
        return false;
    }
}

//压栈操作
bool Push(SqStack *s, char c) {
    if (s->top == MaxSize - 1) {
        return false;
    }
    s->data[++s->top] = c;
    return true;
}

//出栈操作
bool Pop(SqStack *s, char *c) {
    if (s->top == -1) {
        return false;
    }
    *c = s->data[s->top--];
    return true;
}

//括号匹配
bool bracketsCheck(char str[], int length) {
    SqStack s;
    InitSqStack(&s);
    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{' ) {
            Push(&s, str[i]);
        }else {
            if (StackEmpty(s)) {
                return false;
            }

            char topElem;
            Pop(&s, &topElem);
            if (str[i]==')' && topElem=='(') {
                return false;
            }
            if (str[i]==']' && topElem=='[') {
                return false;
            }
            if (str[i]=='}' && topElem=='{') {
                return false;
            }
        }
    }
    return StackEmpty(s);
}

int main(void) {
    return 0;
}
