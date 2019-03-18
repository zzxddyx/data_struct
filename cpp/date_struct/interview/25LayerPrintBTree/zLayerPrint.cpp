/*************************************************************************
    > File Name: zLayerPrint.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月18日 星期一 08时26分30秒
 ************************************************************************/

#include <iostream>
#include <stack>
#include "../common/BTree.h"

using namespace std;

void zLayerPrint(BTNODE *pRoot)
{
    if (pRoot == NULL)
        return;

    stack<BTNODE*> stackNode[2];
    int curLayer = 0;
    int nextLayer = 1;
    stackNode[curLayer].push(pRoot);

    while(!stackNode[0].empty() || !stackNode[1].empty())
    {
        BTNODE *pNode = stackNode[curLayer].top();
        stackNode[curLayer].pop();
        cout << pNode->data << " ";

        if (curLayer == 0)
        {
            if(pNode->lChild != NULL)
                stackNode[nextLayer].push(pNode->lChild);

            if(pNode->rChild != NULL)
                stackNode[nextLayer].push(pNode->rChild);
        }
        else
        {
            if(pNode->rChild != NULL)
                stackNode[nextLayer].push(pNode->rChild);

            if(pNode->lChild != NULL)
                stackNode[nextLayer].push(pNode->lChild);
        }

        if(stackNode[curLayer].empty())
        {
            cout << endl;
            curLayer = 1 - curLayer;
            nextLayer = 1 - nextLayer;
        }
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

    zLayerPrint(p1);
    cout << endl;

    return 0;
}
