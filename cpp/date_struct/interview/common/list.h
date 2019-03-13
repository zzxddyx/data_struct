#include<iostream>
using namespace std;

typedef struct listNode
{
    struct listNode *next;
    int data;
}ListNode;


void InsertHead(ListNode **pHead, int value)
{
    ListNode *pNew = new ListNode;
    pNew->data = value;
    pNew->next = NULL;

    if ((*pHead) == NULL)
    {
        (*pHead) = pNew;
    }
    else
    {
        pNew->next = (*pHead);
        (*pHead) = pNew;
    }
}

void InsertTail(ListNode **pHead, int value)
{
    ListNode *pNew = new ListNode;
    pNew->data = value;
    pNew->next = NULL;

    if((*pHead) == NULL)
    {
        (*pHead) = pNew;
    }
    else
    {
        ListNode *pTmp = (*pHead);
        while(pTmp->next != NULL)
        {
            pTmp = pTmp->next;
        }
        pTmp->next = pNew;
    }
}

void Print(ListNode *pHead)
{
    while(pHead != NULL) 
    {
        cout << pHead->data << " ";
        pHead = pHead->next;
    }
    cout << endl;

}
