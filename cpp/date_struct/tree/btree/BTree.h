#ifndef _BTREE_H_
#define _BTREE_H_

#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

typedef struct _BTree
{
    char data;
    struct _BTree *lChild;
    struct _BTree *rChild;
}BTreeNode, *pBTreeNode;

class BTree
{
    public:
        BTree();
        ~BTree();

    public:
        // 创建
        void CreateBTree();
        // 递归输出树中的结点
        void PreOrderTraverse();
        void MidOrderTracerse();
        void PostOrderTracerse();
        // 非递归输出树中结点
        void PreOrder();
        void MidOrder();
        void PostOrder();
        // 层序遍历
        void LayerOrder();
        // 销毁
        void DestoryBTree();
        void DestoryBTree_Queue();
        //判断树是否为空
        bool isEmpty();
        // 求二叉树中结点x的双亲结点
        BTreeNode* FindParents(BTreeNode *node);
        // 根据value获取结点
        BTreeNode *ByValueGetNode(char value);
        // 返回某结点的左右孩子
        BTreeNode *GetLeftChild(BTreeNode *node);
        BTreeNode *GetRightChile(BTreeNode *node);
        // 返回树的深度
        int GetBTreeDepth();
        // 输出叶子结点
        void OutPutLeaft();
        // 获取结点个数
        int GetNodeNum();
        // 根据前序和中序构造树
        void CreateBtreeBYPreMid(string &pre_str, string &mid_str);
        // 在二叉搜索树中查找第k个最大值
        BTreeNode *GetMaxKValue(int value);
        // 查找与根节点距离k的节点
        void GetDepthKNode(int k);
        // 在二叉树中查找给定节点的祖先节点
        BTreeNode *GetParents(BTreeNode *node);

    private:
        void Create(BTreeNode **node);

        void PreOrderOutput(BTreeNode *node);
        void MidOrderOutput(BTreeNode *node);
        void PostOrderOutput(BTreeNode *node);

        void _PreOrder(BTreeNode *root);
        void _MidOrder(BTreeNode *root);
        void _PostOrder(BTreeNode *root);

        void _LayerOrder(BTreeNode *root);

        void _DestroyBTree(BTreeNode **node);
        void _DestroyBTree_Queue(BTreeNode **node);

        BTreeNode* _FindParents(BTreeNode *root, BTreeNode *node);
        BTreeNode* _ByValueGetNode(BTreeNode *root, char c);

        BTreeNode* _GetLeftChild(BTreeNode *root, BTreeNode *node);
        BTreeNode* _GetRightChild(BTreeNode *root, BTreeNode *node);

        int _GetBtreeDepth(BTreeNode *root);

        void _OutPutLeaft(BTreeNode *root);

        int _GetNodeNum(BTreeNode *root);

        void _GetDepthKNode(BTreeNode *root, int k);

        BTreeNode *_GetParents(BTreeNode *root, BTreeNode *node);
    private:
        BTreeNode *root;
};

#endif //_BTREE_H_

