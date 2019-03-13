#include <iostream>
#include <stack>
#include "../common/list.h"

using namespace std;

void Revert(ListNode *pHead)
{
    if(pHead == NULL || pHead->next == NULL)
        return;

    stack<ListNode*> listStack;
    ListNode *pTmp = pHead;
    while(pTmp != NULL)
    {
        listStack.push(pTmp);
        pTmp = pTmp->next;
    }

    while(!listStack.empty())
    {
        ListNode *pNode = listStack.top();
        cout << pNode->data << " ";
        listStack.pop();
    }
    cout << endl;
}

void Revert1(ListNode *pHead)
{
    if (pHead != NULL)
    {
        if (pHead->next != NULL)
        {
            Revert1(pHead->next);
        }

        cout << pHead->data << " ";
    }
}

int main(void)
{
    ListNode *pHead = NULL;

    InsertTail(&pHead, 3);
    InsertTail(&pHead, 4);
    InsertTail(&pHead, 5);
    InsertTail(&pHead, 6);
    InsertTail(&pHead, 7);
    InsertTail(&pHead, 8);

    Print(pHead);
    cout << "====================" << endl;
    Revert1(pHead);

    return 0;
}
