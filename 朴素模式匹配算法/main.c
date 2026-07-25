#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXLEN 255
typedef struct {
    char ch[MAXLEN];
    int length;
}SString;

bool InitSString(SString* s) {
    s->length = 0;
    return true;
}

bool StrAppend(SString *S,char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (S->length >= MAXLEN-1) {
            return false;
        }
        S->length++;
        S->ch[S->length] = str[i];
        i++;
    }
    return true;
}

int Index(SString S,SString T) {
    int i=1,j=1;
    while (i<=S.length && j<=T.length) {
        if (S.ch[i]==T.ch[j]) {
            ++i;++j;
        }else {
            i = i-j+2;
            j = 1;
        }
    }
    if (j>T.length) {
        return i-T.length;
    }else {
        return 0;
    }
}

int main(void) {
    SString S;
    SString T;
    InitSString(&S);
    InitSString(&T);
    StrAppend(&S,"aaaaab");
    StrAppend(&T,"aab");
    Index(S,T);
    printf("%d\n",Index(S,T));
    return 0;
}
