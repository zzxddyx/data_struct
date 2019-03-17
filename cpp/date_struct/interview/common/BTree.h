#ifndef _BTREE_H_
#define _BTREE_H_

#include <iostream>
using namespace std;

typedef struct _BTReeNode
{
    double data;
    struct _BTReeNode* lChild;
    struct _BTReeNode* rChild;
}BTNODE;

BTNODE* Create(double value)
{
    BTNODE *pNew = new BTNODE();
    pNew->data = value;
    pNew->lChild = NULL;
    pNew->rChild = NULL;

    return pNew;
}

void ConnectTree(BTNODE *pParent, BTNODE *pLchild, BTNODE *pRchild)
{
    if (pParent != NULL)
    {
        pParent->lChild = pLchild;
        pParent->rChild = pRchild;
    }
}

void MidOrderPrint(BTNODE *pRoot)
{
    if (pRoot != NULL)
    {
        MidOrderPrint(pRoot->lChild);
        cout << pRoot->data << " ";
        MidOrderPrint(pRoot->rChild);
    }
}

#endif //_BTREE_H_
