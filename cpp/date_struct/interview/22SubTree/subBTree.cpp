/*************************************************************************
    > File Name: subBTree.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月17日 星期日 16时34分54秒
 ************************************************************************/

#include <iostream>
#include "../common/BTree.h"
using namespace std;

bool EqualData(double value1, double value2)
{
    double valueSub = value1 - value2;
    bool res = false;
    if(valueSub > -0.0000001 && valueSub < 0.0000001)
        res = true;
    return res;
}

bool checkSubInRoot(BTNODE *pRoot, BTNODE *pSub)
{
    if(pSub == NULL)
        return true;
    if (pRoot == NULL)
        return false;
    if(!EqualData(pRoot->data, pSub->data))
        return false;

    return checkSubInRoot(pRoot->lChild, pSub->lChild) && checkSubInRoot(pRoot->rChild, pRoot->rChild);
}

bool CheckSub(BTNODE *pRoot, BTNODE *pSub)
{
    bool result = false;

    if (pRoot != NULL && pSub != NULL)
    {
        if(EqualData(pRoot->data, pSub->data))
            result = checkSubInRoot(pRoot, pSub);
        if (!result)
            result = CheckSub(pRoot->lChild, pSub);
        if(!result)
            result = CheckSub(pRoot->rChild, pSub);
    }

    return result;
}

int main(void)
{
    BTNODE *p1 = Create(1.1);
    BTNODE *p2 = Create(2.1);
    BTNODE *p3 = Create(3.1);
    BTNODE *p4 = Create(4.1);
    BTNODE *p5 = Create(5.1);
    BTNODE *p6 = Create(6.1);
    BTNODE *p7 = Create(7.1);

    ConnectTree(p1, p2, p3);
    ConnectTree(p2, p4, p5);
    ConnectTree(p3, p6, p7);
    MidOrderPrint(p1);
    cout << endl;

    BTNODE *pp1 = Create(4.1);
    BTNODE *pp2 = Create(6.1);
    BTNODE *pp3 = Create(7.1);

    ConnectTree(pp1, pp2, pp3);
    MidOrderPrint(pp1);
    cout << endl;

    cout << CheckSub(p1, pp1) << endl;

    return 0;
}
