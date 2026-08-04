#include <stdio.h>

//并查集的初始化
#define SIZE 13
int UFSet[SIZE]; //集合元素数组
void Initial(int s[]) {
    for (int i = 0; i < SIZE; i++) {
        s[i] = -1;
    }
}

//Find "查操作",找x所属集合(返回x所属根节点)
int Find(int s[],int x) {
    int root = x;
    while (s[root] >= 0 ) { //循环寻找x的根
        root = s[root];
    }
    while (x!=root) { //压缩路径
        int t = s[x]; //t指向x的父结点
        s[x] = root; //x直接挂到根结点下
        x = t;
    }
    return root; //返回根结点编号
}

//Union "并"操作,将两个集合合并为一个
void Union(int s[],int Root1,int Root2) {
    //要求Root1与Root2是不同的集合
    if (Root1 == Root2) {
        return;
    }
    if (s[Root2]>s[Root1]) { //Root2结点数更少
        s[Root1] += s[Root2]; //累加结点总数
        s[Root2] = Root1; //小树合并到大树
    }else {
        s[Root2] += s[Root1]; //累加结点总数
        s[Root1] = Root2; //小树合并到大树
    }
}

int main(void) {
    int s[SIZE];
    Initial(s);

    return 0;
}
