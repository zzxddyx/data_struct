/*************************************************************************
    > File Name: layerPrintBTree.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月17日 星期日 21时50分09秒
 ************************************************************************/

#include <iostream>
#include <deque>
#include "../common/BTree.h"
using namespace std;

void LayerOutBTree(BTNODE *pRoot)
{
    if(pRoot == NULL)
        return;

    deque<BTNODE *> dequeBTnode;
    dequeBTnode.push_back(pRoot);

    while(dequeBTnode.size() > 0)
    {
        BTNODE *pNode = dequeBTnode.front();
        dequeBTnode.pop_front();

        cout << pNode->data << " ";

        if(pNode->lChild != NULL)
            dequeBTnode.push_back(pNode->lChild);

        if(pNode->rChild != NULL)
            dequeBTnode.push_back(pNode->rChild);
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

    LayerOutBTree(p1);
    cout << endl;
 
    return 0;
}
