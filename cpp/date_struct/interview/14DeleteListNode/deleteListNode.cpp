/*************************************************************************
    > File Name: deleteListNode.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月16日 星期六 17时03分37秒
 ************************************************************************/

#include <iostream>
#include "../common/List.h"
using namespace std;

void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
    if (pListHead == NULL || (*pListHead) == NULL || pToBeDeleted == NULL)
        return;

    if (pToBeDeleted->next == NULL && ((*pListHead) == pToBeDeleted))
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        (*pListHead) = NULL;
    }
    else if (pToBeDeleted->next != NULL)
    {
        ListNode *pNext = pToBeDeleted->next;
        pToBeDeleted->data = pNext->data;
        pToBeDeleted->next = pNext->next;
        delete pNext;
        pNext = NULL;
    }
    else
    {
        ListNode *pTmp = (*pListHead);
        while (pTmp->next != pToBeDeleted)
        {
            pTmp = pTmp->next;
        }

        pTmp->next == NULL;
        delete pTmp->next;
        pTmp->next = NULL;
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
    ConnectListNode(p6, NULL);

    Print(p1);

    cout << "=============================" << endl;

    DeleteNode(&p1, p4);
    Print(p1);

    return 0;
}
