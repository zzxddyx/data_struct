/*************************************************************************
    > File Name: BT2DL.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月19日 星期二 08时12分58秒
 ************************************************************************/

#include <iostream>
#include "../common/BTree.h"
using namespace std;

void ConvertNode(BTNODE *pRoot, BTNODE **pListNode)
{
    if (pRoot == NULL)
        return;

    BTNODE *pCurrent = pRoot;
    if (pCurrent->lChild != NULL)
        ConvertNode(pRoot->lChild, pListNode);

    pCurrent->lChild =*pListNode;
    if (*pListNode != NULL)
        (*pListNode)->rChild = pCurrent;

    *pListNode = pCurrent;

    if(pCurrent->rChild != NULL)
        ConvertNode(pCurrent->rChild, pListNode);
}

BTNODE* Convert(BTNODE *pRoot)
{
    if (pRoot == NULL)
        return NULL;

    BTNODE *pListNode = NULL;
    ConvertNode(pRoot, &pListNode);

    BTNODE *pHeadOfLit = pListNode;
    while(pHeadOfLit != NULL && pHeadOfLit->lChild != NULL)
        pHeadOfLit = pHeadOfLit->lChild;

    return pHeadOfLit;
}

void Print(BTNODE *pRoot)
{
    if (pRoot == NULL)
        return;

    BTNODE *pNode = pRoot;
    while(pNode != NULL)
    {
        cout << pNode->data << " ";
        if (pNode->rChild == NULL)
            break;

        pNode = pNode->rChild;
    }

    while (pNode != NULL)
    {
        cout << pNode->data << " ";
        if (pNode->lChild == NULL)
            break;

        pNode = pNode->lChild;
    }
}

int main(void)
{
    BTNODE *p1 = Create(1);
    BTNODE *p2 = Create(2);
    BTNODE *p3 = Create(3);
    BTNODE *p4 = Create(4);
    BTNODE *p5 = Create(5);
    BTNODE *p6 = Create(6);
    BTNODE *p7 = Create(7);

    ConnectTree(p1, p2, p3);
    ConnectTree(p2, p4, p5);
    ConnectTree(p3, p6, p7);

    MidOrderPrint(p1);
    cout << endl;

    BTNODE *head = Convert(p1);
    Print(head);


    return 0;
}
