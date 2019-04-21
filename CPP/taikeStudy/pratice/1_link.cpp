/*************************************************************************
    > File Name: link.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年04月21日 星期日 13时47分30秒
 ************************************************************************/

#include <iostream>

typedef struct _LinkNode
{
    int value;
    struct _LinkNode *next;
}NODE;

NODE *createNode(int data)
{
    NODE *pNew = new NODE;
    pNew->next = NULL;
    pNew->value = data;

    return pNew;
}

void connectNode(NODE *pPre, NODE *pCur)
{
    if (pPre == NULL)
        return;

    pPre->next = pCur;
}

void printNode(NODE *pHead)
{
    NODE *pTmp = pHead;

    while (pTmp != NULL)
    {
        std::cout << pTmp->value << " ";
        pTmp = pTmp->next;
    }

    std::cout << std::endl;
}

NODE *revertList(NODE *pHead)
{
    NODE *pCur = pHead;
    NODE *pNewHead = NULL;
    NODE *pPre = NULL;

    while(pCur != NULL)
    {
        NODE *pNext = pCur->next;
        if(pNext == NULL)
            pNewHead = pCur;

        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
    }

    return pNewHead;
}

int main(void)
{
    NODE *p1 = createNode(1);
    NODE *p2 = createNode(2);
    NODE *p3 = createNode(3);
    NODE *p4 = createNode(4);
    NODE *p5 = createNode(5);
    NODE *p6 = createNode(6);

    connectNode(p1, p2);
    connectNode(p2, p3);
    connectNode(p3, p4);
    connectNode(p4, p5);
    connectNode(p5, p6);

    printNode(p1);

    NODE *pNewHead = revertList(p1);
    printNode(pNewHead);

    return 0;
}
