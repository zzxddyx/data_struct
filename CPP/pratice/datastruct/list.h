#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>

typedef struct LIST
{
    int data;
    struct LIST *next;
}NODE;

NODE *create(int n); // 创建
void connect(NODE *pcur, NODE *pnext); // 结点链接
int length(NODE *phead); // 求长度
void print(NODE *phead); // 打印
NODE *search(NODE *phead, int pos); // 但链表结点的查找
NODE *insert(NODE *phead, int data); // 结点的插入
NODE *delets(NODE *phead, int pos); // 结点删除
NODE *reverse(NODE *phead); // 翻转
NODE *search_mid(NODE *phead); // 寻找中间元素
NODE *sort(NODE *phead); // 排序
NODE *isLoop(NODE *phead); // 判断是否有环
NODE *loopStart(NODE *phead);
NODE *merge(NODE *phead1, NODE *phead2); // 两个有序链表合并
NODE *mergeList(NODE *phead1, NODE *phead2);
NODE *mergeInsert(NODE *phead, NODE *node);

#endif //_LIST_H_
