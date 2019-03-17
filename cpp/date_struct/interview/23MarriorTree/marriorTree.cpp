/*************************************************************************
    > File Name: marriorTree.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月17日 星期日 19时27分03秒
 ************************************************************************/

#include <iostream>
#include "../common/BTree.h"
#include <stack>
using namespace std;

void MarriorTree(BTNODE *pRoot)
{
    if (pRoot == NULL)
        return;

    if(pRoot->lChild == NULL && pRoot->rChild == NULL)
        return;

    BTNODE *pTmp = pRoot->lChild;
    pRoot->lChild = pRoot->rChild;
    pRoot->rChild = pTmp;

    if(pRoot->lChild != NULL)
        MarriorTree(pRoot->lChild);

    if(pRoot->rChild != NULL)
        MarriorTree(pRoot->rChild);
}

void MarriorTreeNotDiGui(BTNODE *pRoot)
{
    if (pRoot == NULL)
        return;

    stack<BTNODE *> stackBtTnode;
    stackBtTnode.push(pRoot);

    while(stackBtTnode.size() > 0)
    {
        BTNODE *pNode = stackBtTnode.top();
        stackBtTnode.pop();

        BTNODE *pTmp = pNode->lChild;
        pNode->lChild = pNode->rChild;
        pNode->rChild = pTmp;

        if(pNode->lChild != NULL)
            stackBtTnode.push(pNode->lChild);

        if(pNode->rChild != NULL)
            stackBtTnode.push(pNode->rChild);
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

    MarriorTree(p1);
    MidOrderPrint(p1);
    cout << endl;

    MarriorTreeNotDiGui(p1);
    MidOrderPrint(p1);
    cout << endl;

    return 0;
}
