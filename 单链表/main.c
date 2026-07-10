#include <stdio.h>
#include <stdlib.h>

//单链表----定义
    //struct LNode {
        //ElemType data;
        //struct LNode *next;
    //};

//单链表----增加一个新的结点
    //struct LNode *p = (struct LNode *) malloc (sizeof(struct LNode));

    //typedef关键字
    //typedef struct LNode LNode;
    //LNode *p = (LNode *) malloc(sizeof(LNode));

//完整定义 (带LinkList)
    //typedef struct LNode {
        //ElemType data;
        //struct LNode *next;
    //}LNode,*LinkList;

//单链表----不带头结点的初始化
    //初始化一个空的单链表
    //bool InitList (LinkList * L) {
        //L = NULL; (空表,暂时还没有结点)
        //return true;
    //}
    //void test () {
        //LinkList L; (声明一个指向单链表的指针,此处没有创建一个结点)
        //InitList(&L); (初始化一个空表)
    //}

    //判断单链表是否为空
    //bool Empty (LinkList L) {
        //return (L == NULL);
    //}

//单链表----带头结点的初始化
    //bool InitList (LinkList * L) {
        //L = (LNode *) malloc(sizeof(LNode)); (分配一个头结点)
        //if (L == NULL) { (内存不足,分配失败)
            //return false;
        //}
        //L->Next = NULL; (头结点之后还没有结点)
        //return true;
    //}
    //void test () {
        //LinkList L;
        //InitList(&L);
    //}

    //判断单链表是否为空 (带头结点)
    //bool Empty (LinkList L) {
        //if (L -> next == NULL) {
            //return true;
        //}else {
            //return false;
        //}
    //}

//单链表----按位序插入 (带头结点)
    //bool ListInsert (LinkList *L,int i,ElemType e) {
        //if (i < 1) {
            //return false;
        //}
        //LNode *p = L->head; (p指向L,L指向头结点,头结点是第0个结点,不存数据)
        //int j = 0; (当前p指向的是第几个结点)
        //while (p != NULL && j < i - 1) { (循环找到第i - 1个结点)
            //p = p->next;
            //j++;
        //}
        //if (p == NULL) { (i值不合法)
            //return false;
        //}
        //LNode *s = (LNode *)malloc(sizeof(LNode));
        //s->data = e;
        //s->next = p->next;
        //p->next = s; (将结点s连到p之后)
        //return true; (插入成功)
    //}

//单链表----按位序插入 (不带头结点)
    //bool ListInsert (LinkList *L,int i,ElemType e) {
        //if (i < 1) {
            //return false;
        //}
        //if (i == 1) { (插入第1个结点的操作与其他结点操作不同)
            //LNode *s = (LNode *)malloc(sizeof(LNode));
            //s->data = e;
            //s->next = L;
            //L = s; (头指针指向新结点)
            //return true;
        //}
        //LNode *p; (指针p指向当前扫描到的结点)
        //int j = 1; (当前p指向的是第几个结点)
        //p = L; (p指向第1个结点,!!!注意:不是头结点)
        //while (p != NULL && j < i - 1) { (循环找到第i - 1个结点)
            //p = p->next;
            //j++;
        //}
        //if (p == NULL) { (i值不合法)
            //return false;
        //}
        //LNode *s = (LNode *)malloc(sizeof(LNode));
        //s->data = e;
        //s->next = p->next;
        //p->next = s;
        //return true; (插入成功)
    //}

//单链表----指定结点的后插操作
    //在p结点之后插入元素e
    //bool InsertNextNode (LNode *p,ElemType e) {
        //if (p == NULL) {
            //return false;
        //}
        //LNode *s = (LNode *)malloc(sizeof(LNode));
        //if (s == NULL) { (内存分配失败)
            //return false;
        //}
        //s->data = e; (用结点s保存数据元素e)
        //s->next = p->next
        //p->next = s (将结点s连到p之后)
        //return true;
    //}

//单链表----指定结点的前插操作
    //在p结点之前插入元素e
    //bool InsertPriorNode (LNode *p,ElemType e) {
        //if (p == NULL){
            //return false;
        //}
        //LNode *s = (LNode *)malloc(sizeof(LNode));
        //if (s == NULL) { (内存分配失败)
            //return false;
        //}
        //s -> next = p -> next;
        //p -> next = s; (新结点s连到p之后)
        //s -> data = p -> data; (将p中元素复制到s中)
        //p -> data = e; (p中元素覆盖为e)
        //return true;
    //}

//单链表----按位序删除 (带头结点)
    //bool ListDelete (LinkList *L,int i,ElemType *e) {
        //if (i < 1) {
            //return false;
        //}
        //LNode *p = L->head; (p指向L,L指向头结点,头结点是第0个结点,不存数据)
        //int j = 0; (当前p指向的是第几个结点)
        //while (p != NULL && j < i - 1) { (循环找到第i - 1个结点)
            //p = p->next;
            //j++;
        //}
        //if (p == NULL) { (i值不合法)
            //return false;
        //}
        //if (p -> next == NULL) { (第i - 1个结点之后已无其他结点)
            //return false;
        //}
        //LNode *q = p -> next; (令q指向被删除结点)
        //e = q -> data; (用e返回元素的值)
        //p -> next = q -> next; (将*q结点从链中断开)
        //free (q); (释放结点的存储空间)
        //return true; (删除成功)
    //}

//单链表----指定结点的删除
    //删除指定结点p
    //bool DeleteNode (LNode *p) {
        //if (p == NULL){
            //return false;
        //}
        //LNode *q = p -> next; (令q指向*p的后继结点)
        //p -> data = p -> next -> data; (和后继结点交换数据域)
        //p -> next = q -> next; (将*q结点从链中断开)
        //free (q); (释放后继节点的存储空间)
        //return true;
    //}

//单链表---- 按位查找,返回第i个元素 (带头结点)
    //LNode * GetElem(LinkList L, int i) {
        //if (i < 0) {
            //return NULL;
        //}
        //LNode * p = L->head; (让p指向头结点)
        //int j = 0; (当前p指向的是第几个结点)
        //while (p != NULL && j < i) { (循环找到第i个结点)
            //p = p->next;
            //j++;
        //}
        //return p;
    //}

//单链表----按值查找,找到数据域==e的结点
    //LNode * LocateElem (LinkList L,ElemType e) {
        //LNode * p = L->next;
        //while (p != NULL && p -> data != e) { (从第1个结点开始查找数据域为e的结点)
            //p = p->next;
        //}
        //return p; (找到后返回该结点指针,否则返回NULL)
    //}

//单链表----求表的长度
    //int Length (LinkList L) {
        //int len = 0;
        //LNode *p = L->head;
        //while (p -> next != NULL) {
            //p = p -> next;
            //len++;
        //}
        //return len;
    //}

//单链表----尾插法建立单链表
    //LinkList List_TailInsert (LinkList *L) { (正向建立单链表)
        //int x; (设置ElemType为整型)
        //L = (LinkList)malloc(sizeof(LNode)); (建立头结点)
        //LNode *s,*r = L; (r为表尾指针)
        //scanf("%d",&x); (输入结点的值)
        //while (x != 9999) { (输入9999表示结束)
            //s = (LinkList)malloc(sizeof(LNode));
            //s -> data = x;
            //r -> next = s;
            //r = s; (指向新的表尾结点)
            //scanf("%d",&x);
        //}
        //r -> next = NULL; (尾结点置空)
        //return L;
    //}

//单链表----头插法建立单链表
    //LinkList List_HeadInsert (LinkList *L) { (逆向建立单链表)
        //LNode *s;
        //int x;
        //L = (LinkList) malloc (sizeof (LNode)); (创建头结点)
        //L -> next = NULL; (初始为空链表)
        //scanf("%d",&x); (输入结点的值)
        //while (x != 9999) { (输入9999表示结束)
            //s = (LNode *) malloc (sizeof (LNode)); (创建新结点)
            //s -> data = x;
            //s -> next = L -> next;
            //L -> next = s; (将新结点插入表中,L为头指针)
            //scanf("%d",&x);
        //}
        //return L;
    //}

