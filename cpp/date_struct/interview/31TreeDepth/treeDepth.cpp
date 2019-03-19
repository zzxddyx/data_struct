#include<iostream>
#include "../common/BTree.h"
using namespace std;

int TreeDepth(BTNODE *pRoot)
{
    if (pRoot == NULL)
        return 0;

    int leftDepth = TreeDepth(pRoot->lChild);
    int rightDepth = TreeDepth(pRoot->rChild);

    return (leftDepth > rightDepth) ? (leftDepth+1) : (rightDepth+1);
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
    BTNODE *p8 = Create(8);
    BTNODE *p9 = Create(8);

    ConnectTree(p1, p2, p3);
    ConnectTree(p2, p4, p5);
    ConnectTree(p3, p6, p7);
    ConnectTree(p7, NULL, p8);

    MidOrderPrint(p1);
    cout << endl;

    cout << TreeDepth(p1) << endl;



    return 0;
}

