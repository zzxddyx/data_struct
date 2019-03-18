/*************************************************************************
    > File Name: layerPrint.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月18日 星期一 08时07分20秒
 ************************************************************************/

#include <iostream>
#include <deque>
#include "../common/BTree.h"
using namespace std;

void Print(BTNODE *pRoot)
{
    if (pRoot == NULL)
        return;

    deque<BTNODE *> dequeNodes;
    dequeNodes.push_back(pRoot);
    int nextLayerCount = 0;
    int toBePrintCount = 0;

    while(dequeNodes.size() > 0)
    {
        BTNODE *node = dequeNodes.front();
        cout << node->data << " ";

        if(node->lChild != NULL)
        {
            dequeNodes.push_back(node->lChild);
            nextLayerCount++;
        }
        if(node->rChild != NULL)
        {
            dequeNodes.push_back(node->rChild);
            nextLayerCount++;
        }

        dequeNodes.pop_front();
        toBePrintCount --;

        if(toBePrintCount <= 0)
        {
            cout << endl;
            toBePrintCount = nextLayerCount;
            nextLayerCount = 0;
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

    Print(p1);
    cout << endl;

    return 0;
}
