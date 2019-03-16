#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
using namespace std;

typedef struct _ListNode
{
    struct _ListNode *next;
    int data;
}ListNode;


ListNode *CreateNode(int value)
{
    ListNode *pNew = new ListNode();
    pNew->data = value;
    pNew->next = NULL;

    return pNew;
}

void ConnectListNode(ListNode *pCurrent, ListNode *pNext)
{
    if (pCurrent == NULL)
        return;

    pCurrent->next = pNext;
}

void Print(ListNode *pHead)
{
    while (pHead != NULL)
    {
        cout << pHead->data << " ";
        pHead = pHead->next;
    }
    cout << endl;
}
#endif //_LIST_H_
