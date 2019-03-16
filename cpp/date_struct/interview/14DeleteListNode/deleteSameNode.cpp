/*************************************************************************
    > File Name: deleteSameNode.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月16日 星期六 17时53分56秒
 ************************************************************************/

#include <iostream>
#include "../common/List.h"
using namespace std;

void DeleteDuplication(ListNode **pHead)
{
    if (pHead == NULL || *pHead == NULL)
        return;

    ListNode *pPre = NULL;
    ListNode *pCur = *pHead;

    while(pCur != NULL)
    {
        ListNode *pNext = pCur->next;
        bool isDelete = false;

        if (pNext != NULL && pCur->data == pNext->data)
            isDelete = true;

        if (!isDelete) 
        {
            pPre = pCur;
            pCur = pNext;
        }
        else 
        {
            int value = pCur->data;
            ListNode *pDeleteNode = pCur;

            while(pDeleteNode != NULL && pDeleteNode->data == value)
            {
                pNext = pDeleteNode->next;

                delete pDeleteNode;
                pDeleteNode = NULL;

                pDeleteNode = pNext;
            }

            if (pPre == NULL)
            {
                *pHead = pNext;
            }
            else
            {
                pPre->next = pNext;
            }
            pCur = pNext;
        }
    }
}

int main(void)
{
    ListNode *p1 = CreateNode(1);
    ListNode *p2 = CreateNode(1);
    ListNode *p31 = CreateNode(3);
    ListNode *p32 = CreateNode(3);
    ListNode *p41 = CreateNode(4);
    ListNode *p42 = CreateNode(4);
    ListNode *p5= CreateNode(5);
    ListNode *p6 = CreateNode(6);

    ConnectListNode(p1, p2);
    ConnectListNode(p2, p31);
    ConnectListNode(p31, p32);
    ConnectListNode(p32, p41);
    ConnectListNode(p41, p42);
    ConnectListNode(p42, p5);
    ConnectListNode(p5, p6);
    ConnectListNode(p6, NULL);

    Print(p1);

    DeleteDuplication(&p1);
    Print(p1);


    return 0;
}
