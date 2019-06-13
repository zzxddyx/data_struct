#ifndef _DOUBLELIST_H_
#define _DOUBLELIST_H_

#include <iostream>

typedef struct LIST
{
    int data;
    struct LIST *next;
    struct LIST *prev;
}NODE;

NODE *create(int value);
void connect(NODE *node1, NODE *node2);
int length(NODE *phead);
void print(NODE *phead);
void insert(NODE *phead, int data);
NODE *delets(NODE *phead, int data);
// 有序双向循环链表的插入操作
// 删除两个双向循环链表的相同结点

#endif //_DOUBLELIST_H_
