#include<iostream>
using namespace std;

typedef struct _BTree
{
    char data;
    struct _BTree *lChild;
    struct _BTree *rChild;
}BTree;


void Create(BTree **pRoot)
{
    char value;
    cin >> value;

    if (value == '#')
    {
        (*pRoot) = NULL;
    }
    else
    {
        (*pRoot) = new BTree;
        (*pRoot)->data = value;
        Create(&(*pRoot)->lChild);
        Create(&(*pRoot)->rChild);
    }
}

void Print(BTree *pRoot)
{
    if (pRoot != NULL)
    {
        Print(pRoot->lChild);
        cout << pRoot->data << " ";
        Print(pRoot->rChild);
    }
}
