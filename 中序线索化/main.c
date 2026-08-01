#include <stdio.h>
#include <stdlib.h>

//线索二叉树结点
typedef struct ThreadNode {
    int data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag; //左右线索标志
}ThreadNode,* ThreadTree;

//全局变量 pre,指向当前访问结点的前驱
ThreadNode *pre = NULL;

//创建单个结点
ThreadTree CreateNode(int val) {
    ThreadNode *p = (ThreadNode *)malloc(sizeof(ThreadNode));
    p->data = val;
    p->lchild = p->rchild = NULL;
    p->ltag = p->rtag = 0;
    return p;
}

//函数前置声明,消除类型冲突
void CreateInThread(ThreadTree T);
void InThread(ThreadTree T);
void visit(ThreadNode *q);

//中序线索化二叉树
void CreateInThread(ThreadTree T) {
    pre = NULL; //pre初始化为NULL
    if (T != NULL) { //非空二叉树才能线索化
        InThread(T); //中序线索化二叉树
        if (pre->rchild==NULL) {
            pre->rtag=1; //处理遍历的最后一个结点
        }
    }
}

//中序遍历二叉树,一边遍历一边线索化
void InThread(ThreadTree T) {
    if (T != NULL) {
        InThread(T->lchild); //中序遍历左子树
        visit(T); //访问根节点
        InThread(T->rchild); //中序遍历右子树
    }
}

void visit(ThreadNode *q) {
    if (q->lchild==NULL) {
        q->lchild=pre;
        q->ltag=1;
    }
    if (pre!=NULL && q->rchild==NULL) {
        pre->rchild=q;
        q->rtag=1;
    }
    pre=q;
}

void DestroyTree(ThreadTree T) {
    if (T == NULL) {
        return;
    }
    if (T->ltag ==0) {
        DestroyTree(T->lchild);
    }
    if (T->rtag ==0) {
        DestroyTree(T->rchild);
    }
    free(T);
}

int main(void) {
    ThreadTree A = CreateNode(1);
    ThreadTree B = CreateNode(2);
    ThreadTree C = CreateNode(3);
    ThreadTree D = CreateNode(4);

    A->lchild = B;
    A->rchild = C;
    B->lchild = D;

    CreateInThread(A);
    printf("线索化执行完毕\n");

    DestroyTree(A);
    return 0;
}
