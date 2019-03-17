/*************************************************************************
    > File Name: mergeSortList.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月17日 星期日 15时09分05秒
 ************************************************************************/

#include <iostream>
#include "../common/List.h"
using namespace std;

ListNode* merge(ListNode *p1, ListNode *p2)
{
    if (p1 == NULL)
        return p2;
    if (p2 == NULL)
        return p1;

    ListNode *newHead = NULL;
    if (p1->data < p2->data)
    {
        newHead = p1;
        newHead->next = merge(p1->next, p2);
    }
    else
    {
        newHead = p2;
        newHead->next = merge(p1, p2->next);
    }
    return newHead;
}

int main(void)
{
    ListNode *p1 = CreateNode(1);
    ListNode *p2 = CreateNode(3);
    ListNode *p3 = CreateNode(5);
    ListNode *p4 = CreateNode(7);
    ListNode *p5 = CreateNode(9);

    ConnectListNode(p1, p2);
    ConnectListNode(p2, p3);
    ConnectListNode(p3, p4);
    ConnectListNode(p4, p5);
    Print(p1);


    ListNode *pp1 = CreateNode(2);
    ListNode *pp2 = CreateNode(4);
    ListNode *pp3 = CreateNode(6);
    ListNode *pp4 = CreateNode(8);
    ListNode *pp5 = CreateNode(10);

    ConnectListNode(pp1, pp2);
    ConnectListNode(pp2, pp3);
    ConnectListNode(pp3, pp4);
    ConnectListNode(pp4, pp5);

    Print(pp1);

    ListNode *pNew = merge(p1, pp1);
    Print(pNew);

    return 0;
}
