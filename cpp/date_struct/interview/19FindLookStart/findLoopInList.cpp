/*************************************************************************
    > File Name: findLoopInList.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月17日 星期日 11时08分18秒
 ************************************************************************/

#include <iostream>
#include "../common/List.h"
using namespace std;

ListNode* checkLoop(ListNode *pHead)
{
    if (pHead == NULL)
        return NULL;

    ListNode *pSlow = pHead->next;
    if (pSlow == NULL)
        return NULL;

    ListNode *pFast = pSlow->next;

    while(pFast != NULL && pSlow != NULL)
    {
        if (pFast == pSlow)
            return pSlow;

        pSlow = pSlow->next;
        pFast = pFast->next;
        if(pFast != NULL)
            pFast = pFast->next;
    }

    return NULL;
}

ListNode *LoopEntry(ListNode *pHead)
{
    ListNode *meetNode = checkLoop(pHead);
    if (meetNode == NULL)
        return NULL;

    int loopNum = 1;
    ListNode *pNode1 = pHead;
    while(pNode1->next != meetNode)
    {
        pNode1 = pNode1->next;
        ++ loopNum;
    }

    pNode1 = pHead;
    for (int i = 0; i < loopNum; ++i)
    {
        pNode1 = pNode1->next;
    }

    ListNode *pNode2 = pHead;
    while(pNode1 != pNode2)
    {
        pNode1 = pNode1->next;
        pNode2 = pNode2->next;
    }
    return pNode1;
}

int main(void)
{
    ListNode *p1 = CreateNode(1);
    ListNode *p2 = CreateNode(2);
    ListNode *p3 = CreateNode(3);
    ListNode *p4 = CreateNode(4);
    ListNode *p5 = CreateNode(5);
    ListNode *p6 = CreateNode(6);
    ListNode *p7 = CreateNode(7);
    ListNode *p8 = CreateNode(8);

    ConnectListNode(p1, p2);
    ConnectListNode(p2, p3);
    ConnectListNode(p3, p4);
    ConnectListNode(p4, p5);
    ConnectListNode(p5, p6);
    ConnectListNode(p6, p7);
    ConnectListNode(p7, p8);
    ConnectListNode(p8, p3);


    ListNode *entry = LoopEntry(p1);
    if (entry != NULL)
        cout << entry->data << endl;
    return 0;

}
