#include "doubleList.h"

NODE *create(int value)
{
    NODE *pNew = new NODE();
    pNew->data = value;
    pNew->next = NULL;
    pNew->prev = NULL;

    return pNew;
}

void connect(NODE *node1, NODE *node2)
{
    if(node1 != NULL && node2 != NULL)
    {
        node1->next = node2;
        node2->prev = node1;
    }
    else if(node2 == NULL && node1 != NULL)
        node1->next = node2;
}

int length(NODE *phead)
{
    if (phead == NULL)
        return 0;

    int len = 0;
    NODE *pTmp = phead;
    while(pTmp != NULL)
    {
        ++len;
        pTmp = pTmp->next;
    }

    return len;
}

void print(NODE *phead)
{
    NODE *pTmp = phead;
    while(pTmp != NULL)
    {
        std::cout << pTmp->data << " ";
        pTmp = pTmp->next;
    }
    std::cout << std::endl;
}

void insert(NODE *phead, int data);
NODE *delets(NODE *phead, int data);

