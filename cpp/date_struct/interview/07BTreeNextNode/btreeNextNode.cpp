/*************************************************************************
    > File Name: btreeNextNode.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月14日 星期四 08时18分34秒
 ************************************************************************/

#include <iostream>
#include "../common/ParentBTree.h"
using namespace std;

BTNODE* NextNODE(BTNODE *node)
{
    if (node == NULL)
        return NULL;

    BTNODE *pResult = NULL;
    if (node->rChild != NULL)
    {
        BTNODE *pTmp = node->rChild;
        while(pTmp->lChild != NULL)
            pTmp = pTmp->lChild;

        pResult = pTmp;
    }
    else if(node->parent != NULL)
    {
        BTNODE *pCur = node;
        BTNODE *pParent = node->parent;

        while(pParent != NULL && pParent->rChild == pCur)
        {
            pCur = pParent;
            pParent = pParent->parent;
        }

        pResult = pParent;
    }
    return pResult;
}

int main(void)
{
    BTNODE *p8 = CreateBTNode(8);
    BTNODE *p6 = CreateBTNode(6);
    BTNODE *p10 = CreateBTNode(10);
    BTNODE *p5 = CreateBTNode(5);
    BTNODE *p7 = CreateBTNode(7);
    BTNODE *p9 = CreateBTNode(9);
    BTNODE *p11 = CreateBTNode(11);

    ConnectTreeNode(p8, p6, p10);
    ConnectTreeNode(p6, p5, p7);
    ConnectTreeNode(p10, p9, p11);

    PrintNodeData(p8);

    cout << "---------------------------------" << endl;

    BTNODE *pRes = NextNODE(p7);
    cout << pRes->data << endl;
    
    return 0;

}
