#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//串的定义 (静态数组)
#define MAXLEN 255 //预定义串的最大长度为255
typedef struct {
    char ch[MAXLEN]; //每个分量存储一个字符
    int length; //串的实际长度
}SString;

//初始化串
bool InitSString(SString* s) {
    s->length = 0;
    return true;
}

//求串长
int StrLength (SString S) {
    if (S.length > MAXLEN) {
        return false;
    }
    return S.length;
}

//求子串
bool SubString (SString *Sub, SString S, int pos, int len) {
    //子串范围越界
    if (pos+len-1 > Sub->length) {
        return false;
    }
    for (int i=pos; i<pos+len; i++) {
        Sub->ch[i-pos+1] = Sub->ch[i];
    }
    Sub->length = len;
    return true;
}

//比较操作。若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0
int StrCompare (SString S, SString T) {
    for (int i = 0; i <= S.length && i <= T.length; i++) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }
    //扫描过的所有字符都相同,则长度长的串更大
    return S.length - T.length;
}

int Index(SString S, SString T) {
    int i,n=StrLength(S),m=StrLength(T);
    SString sub;
    while (i<=n-m+1) {
        SubString(&sub,S,i,m);
        if (StrCompare(sub,T)!=0) {
            ++i;
        }else {
            return i;
        }
    }
    return 0;
}

int main(void) {
    SString S;
    InitSString(&S);
    return 0;
}
