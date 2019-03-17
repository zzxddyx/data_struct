/*************************************************************************
    > File Name: revertList.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月17日 星期日 12时57分03秒
 ************************************************************************/

#include <iostream>
#include "../common/List.h"
using namespace std;

ListNode* Revert(ListNode *pHead)
{
    ListNode *NewHead = NULL;
    ListNode *curNode = pHead;
    ListNode *preNode = NULL;

    while (curNode != NULL)
    {
        ListNode *nextNode = curNode->next;
        if(nextNode == NULL)
            NewHead = curNode;

        curNode->next = preNode;
        preNode = curNode;
        curNode = nextNode;
    }

    return NewHead;
}

void Revert1(ListNode **pHead)
{
    ListNode *curNode = *pHead;
    ListNode *preNode = NULL;

    while(curNode != NULL)
    {
        ListNode *nextNode = curNode->next;
        if (nextNode == NULL)
            *pHead = curNode;

        curNode->next = preNode;
        preNode = curNode;
        curNode = nextNode;

    }
}

int main(void)
{ 
    ListNode *p1 = CreateNode(1);
    ListNode *p2 = CreateNode(2);
    ListNode *p3 = CreateNode(3);
    ListNode *p4 = CreateNode(4);
    ListNode *p5 = CreateNode(5);
    ListNode *p6 = CreateNode(6);

    ConnectListNode(p1, p2);
    ConnectListNode(p2, p3);
    ConnectListNode(p3, p4);
    ConnectListNode(p4, p5);
    ConnectListNode(p5, p6);

    Print(p1);
    ListNode *pNew = Revert(p1);
    Print(pNew);
    Revert1(&pNew);
    Print(pNew);

    return 0;
}
