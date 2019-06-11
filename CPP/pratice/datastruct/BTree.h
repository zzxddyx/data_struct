#ifndef _BTREE_H_
#define _BTREE_H_

typedef struct _BTree
{
    int data;
    struct _BTree *parent;
    struct _BTree *left;
    struct _BTree *right;
}BTNODE;

class BTree
{
    public:
        BTree(int *arr, int len);
        ~BTree();

    public:
        void insertNodeNM(int data);
        void insertNodeDG(int data); 

        void InOrderTreeNM();
        void InOrderTreeDG();
        void PreOrderTreeNM();
        void PreOrderTreeDG();
        void PostOrderTreeNM();
        void PostOrderTreeDG();
        void LayerOrderTreeDG();

    private:
        BTNODE *root;
};


#endif //_BTREE_H_
