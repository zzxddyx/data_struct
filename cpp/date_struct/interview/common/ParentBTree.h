/*************************************************************************
    > File Name: ParentBTree.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月14日 星期四 08时02分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct _BinaryTreeNode
{
    int data;
    struct _BinaryTreeNode *parent;
    struct _BinaryTreeNode *lChild;
    struct _BinaryTreeNode *rChild;
}BTNODE;

BTNODE* CreateBTNode(int value)
{
    BTNODE *pNode = new BTNODE();
    pNode->data = value;
    pNode->parent = NULL;
    pNode->lChild = NULL;
    pNode->rChild = NULL;

    return pNode;
}

void ConnectTreeNode(BTNODE *parent, BTNODE *lChild, BTNODE *rChild)
{
    if(parent != NULL)
    {
        parent->lChild = lChild;
        parent->rChild = rChild;

        if(lChild != NULL)
            lChild->parent = parent;
        if(rChild != NULL)
            rChild->parent = parent;
    }
}

void PrintNodeData(BTNODE *node)
{
    if(node != NULL)
    {
        PrintNodeData(node->lChild);
        cout << node->data << " ";
        PrintNodeData(node->rChild);
    }
    cout << endl;
}

void DestroyTree(BTNODE *pRoot)
{
    if(pRoot != NULL)
    {
        BTNODE *lchild = pRoot->lChild;
        BTNODE *rchild = pRoot->rChild;

        delete pRoot;
        pRoot = NULL;

        DestroyTree(lchild);
        DestroyTree(rchild);
    }
}


