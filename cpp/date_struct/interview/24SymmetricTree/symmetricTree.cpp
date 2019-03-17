/*************************************************************************
    > File Name: symmetricTree.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月17日 星期日 20时06分11秒
 ************************************************************************/

#include <iostream>
#include "../common/BTree.h"
using namespace std;

bool _isSymmtricTree(BTNODE *pRoot1, BTNODE *pRoot2)
{
    if (pRoot1 == NULL && pRoot2 == NULL)
        return true;

    if (pRoot1 == NULL || pRoot2 == NULL)
        return false;

    if(pRoot1->data != pRoot2->data)
        return false;

    return _isSymmtricTree(pRoot1->lChild, pRoot2->rChild) && _isSymmtricTree(pRoot1->rChild, pRoot2->lChild);
}

bool isSymmtricTree(BTNODE *pRoot)
{
    return _isSymmtricTree(pRoot, pRoot);
}

int main(void)
{
    BTNODE *p1 = Create(8);
    BTNODE *p2 = Create(6);
    BTNODE *p3 = Create(6);
    BTNODE *p4 = Create(5);
    BTNODE *p5 = Create(7);
    BTNODE *p6 = Create(7);
    BTNODE *p7 = Create(5);

    ConnectTree(p1, p2, p3);
    ConnectTree(p2, p4, p5);
    ConnectTree(p3, p6, p7);

    MidOrderPrint(p1);
    cout << endl;

    cout << isSymmtricTree(p1) << endl;

    return 0;
}
