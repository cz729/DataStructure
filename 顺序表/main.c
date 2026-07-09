#include <stdio.h>
#include <stdlib.h>

//顺序表----静态分配
    //#define MaxSize 10
    //typedef struct {
        //int data[MaxSize];
        //int length;
    //}SqList;

    //void InitList(SqList *L) {
        //L->length = 0;
    //}

    //int main() {
        //SqList L;
        //InitList(&L);
    //}

//顺序表----动态分配
    //#define InitSize 10
    //typedef struct {
        //int *data;
        //int MaxSize;
        //int length;
    //}SeqList;

    //void InitList(SeqList *L) {
        //L -> data = (int *)malloc(sizeof(int)*InitSize);
        //L -> length = 0;
        //L -> MaxSize = InitSize;
    //}

    //void IncreaseSize(SeqList *L , int len) {
        //int *p = L -> data;
        //L -> data = (int *)malloc((L -> MaxSize + len) * sizeof(int));
        //for (int i = 0; i < len; i++) {
            //L -> data[i] = *p;
        //}
        //L -> MaxSize += len;
        //free(p);
    //}

    //int main(void) {
        //SeqList L;
        //InitList(&L);
        //return 0;
    //}

//顺序表----存入数据 (从尾部存入数据)
    //bool AddTail(SqList *L,int val) {
        //if (L -> length >= MaxSize) {
            //printf("顺序表已满,无法存入/n");
            //return false;
        //}
        //L -> data[L -> length] = val;
        //L -> length++;
        //return true;
    //}
    //后续调用,如:AddTail(&L,10);
    //用cout 输出调用函数的代码来得到代码是否成功运行,成功输出1,失败输出0

//顺序表----插入数据 (在L中位序i处插入元素e)
    //bool ListInsert(SqList *L,int i,int e) {
        //if (i < 1 || i > L -> length+1) {
            //return false;
        //}
        //if (L -> length >= MaxSize) {
            //return false;
        //}
        //for (int j = L->length; j >= i; j--) {  (将第i个元素及以后的元素后移)
            //L->data[j] = L->data[j-1];
        //}
        //L->data[i-1] = e; (在位置i放入e)
        //L->length++; (长度加1)
        //return true;
    //}
    //用cout输出调用函数的代码,成功输出1,失败输出0

//顺序表----删除数据 (删除在L中位序为i的元素,并用e返回删除元素的值)
    //bool ListDelete(Sqlist *L,int i,int *e) { (判断i的范围是否有效)
        //if (i < 1 || i > L -> length+1) {
            //return false;
        //}
        //e = L -> data[i-1]; (将被删除的元素赋值给e)
        //for (int j = i; j < L -> length; j++) { (将第i个位置后的元素前移)
            //L -> data[j-1] = L -> data[j];
        //}
        //L -> length--; (线性表长度见1)
        //return true;
    //}
    //使用前要先定义一个同类型变量e

//顺序表----按位查找 (获取在L中位序为i的元素的值)
    //静态分配
    //ElemType GetElem(SqList L,int i) {
        //return L -> data[i-1];
    //}

    //动态分配
    //ElemType GetElem(SqList L,int i) {
        //return L -> data[i-1];
    //}

//顺序表----按值查找 (在L中查找具有给定关键字值的元素)
    //int LocateElem(SeqList L,int e) {
        //for (int i = 0; i < L -> length; i++) {
            //if (L -> data[i] == e) { (两个结构类型元素不能用==比较是否相等,要自己写代码或者函数分别比较结构体里的变量是否相等)
                //return i+1;
            //}
        //}
        //return 0;
    //}