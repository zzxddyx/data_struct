#include <iostream>
#include <vector>
#include "../common/BTree.h"
using namespace std;

void _FindPath(BTNODE *pRoot, int sum, vector<BTNODE*> &path, int curSum)
{
    curSum += pRoot->data;
    path.push_back(pRoot);

    bool isLeaf = (pRoot->lChild == NULL) && (pRoot->rChild == NULL);
    if (isLeaf && curSum == sum)
    {
        cout << "find this path" << endl;
        for (vector<BTNODE*>::iterator iter = path.begin(); iter != path.end(); ++iter)
        {
            cout << (*iter)->data << " ";
        }
        cout << endl;
    }

    if (pRoot->lChild != NULL)
        _FindPath(pRoot->lChild, sum, path, curSum);

    if(pRoot->rChild != NULL)
        _FindPath(pRoot->rChild, sum, path, curSum);

    //curSum -= pRoot->data;
    path.pop_back();
}

void FindPath(BTNODE *pRoot, int sum)
{
    if (NULL == pRoot)
        return;

    vector<BTNODE*> path;
    int curSum = 0;

    _FindPath(pRoot, sum, path, curSum);
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

    FindPath(p1, 8);

    return 0;
}
