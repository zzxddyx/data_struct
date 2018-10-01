#include "BTree.h"

BTree::BTree()
{
    root = NULL;
    cout << "create a tree successful" << endl;
}

BTree::~BTree()
{
    this->DestoryBTree();
}

void BTree::CreateBTree()
{
    Create(&root);
}

void BTree::Create(BTreeNode **node)
{
    char ch;
    cin >> ch;

    if ('#' == ch)
    {
        node = NULL;
    }
    else
    {
        (*node) = new BTreeNode();
        (*node)->data = ch;
        Create(&(*node)->lChild);
        Create(&(*node)->rChild);
    }
}

void BTree::PreOrderOutput(BTreeNode *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        PreOrderOutput(node->lChild);
        PreOrderOutput(node->rChild);
    }
}

void BTree::PreOrderTraverse()
{
    PreOrderOutput(root);
    cout << endl;
}

void BTree::MidOrderTracerse()
{
    MidOrderOutput(root);
    cout << endl;

}
void BTree::MidOrderOutput(BTreeNode *node)
{
    if (node != NULL)
    {
        MidOrderOutput(node->lChild);
        cout << node->data << " ";
        MidOrderOutput(node->rChild);
    }
}

void BTree::PostOrderTracerse()
{
    PostOrderOutput(root);
    cout << endl;
}

void BTree::PostOrderOutput(BTreeNode *node)
{
    if (node != NULL)
    {
        PostOrderOutput(node->lChild);
        PostOrderOutput(node->rChild);
        cout << node->data << " ";
    }
}

void BTree::DestoryBTree()
{
    this->_DestroyBTree(&root);
}

void BTree::_DestroyBTree(BTreeNode **root)
{
    if ((*root) != NULL)
    {
        _DestroyBTree(&(*root)->lChild);
        _DestroyBTree(&(*root)->rChild);
        delete (*root);
        (*root) = NULL;
    }
}

/*
 * 1. 将root压进队列
 * 2. free 队列头元素
 * 3. 将左右孩子放入队列,重复执行1,2
 */
void BTree::DestoryBTree_Queue()
{
    this->_DestroyBTree_Queue(&root);
}

void BTree::_DestroyBTree_Queue(BTreeNode **node)
{
    queue<BTreeNode*> queueTree;
    BTreeNode *TmpNode = NULL;

    if ((*node) == NULL)
    {
        return;
    }

    TmpNode = (*node);
    queueTree.push(TmpNode);

    while (!queueTree.empty())
    {
        TmpNode = queueTree.front();
        queueTree.pop();

        if (TmpNode->lChild != NULL)
        {
            queueTree.push(TmpNode->lChild);
        }
        if (TmpNode->rChild != NULL)
        {
            queueTree.push(TmpNode->rChild);
        }

        delete TmpNode;
    }
}

bool BTree::isEmpty()
{
    if (root)
    {
        return false;
    }
    else
    {
        return true;
    }
}

BTreeNode* BTree::FindParents(BTreeNode *node)
{
    return this->_FindParents(root, node);
}

BTreeNode* BTree::_FindParents(BTreeNode *root, BTreeNode *node)
{
    BTreeNode *Temp = NULL;
    BTreeNode *pRoot = root;
    
    if (pRoot == NULL || pRoot->lChild == node || pRoot->rChild == node)
    {
        return pRoot;
    }

    Temp = _FindParents(pRoot->lChild, node);
    if (Temp == NULL)
    {
        Temp = _FindParents(pRoot->rChild, node);
    }
    return Temp;
}

BTreeNode* BTree::ByValueGetNode(char value)
{
    return  this->_ByValueGetNode(root, value);
}

BTreeNode* BTree::_ByValueGetNode(BTreeNode *root, char value)
{
    BTreeNode *pRoot = root;
    BTreeNode *pTemp = NULL;
    if (pRoot == NULL)
        return NULL;

    if (pRoot->data == value)
        return pRoot;

    pTemp = _ByValueGetNode(pRoot->lChild, value);
    if (pTemp != NULL)
    {
        return pTemp;
    }
    else
    {
        return _ByValueGetNode(pRoot->rChild, value);
    }
}

BTreeNode* BTree::GetLeftChild(BTreeNode *node)
{
    return this->_GetLeftChild(root, node);
}

BTreeNode* BTree::_GetLeftChild(BTreeNode *root, BTreeNode *node)
{
    if (root != NULL)
    {
        if (root && root->lChild == node || root->rChild == node)
        {
            return node->lChild;
        }
        else
        {
            _GetLeftChild(root->lChild, node);
            _GetLeftChild(root->rChild, node);
        }
    }
}

BTreeNode* BTree::GetRightChile(BTreeNode *node)
{
    return this->_GetRightChild(root, node);
}

BTreeNode* BTree::_GetRightChild(BTreeNode *root, BTreeNode *node)
{
    if (root != NULL)
    {
        if (root && root->lChild == node || root->rChild == node)
        {
            return node->rChild;
        }
        else
        {
            _GetRightChild(root->lChild, node);
            _GetRightChild(root->rChild, node);
        }
    }
}

int BTree::GetBTreeDepth()
{
    return this->_GetBtreeDepth(root);
}

int BTree::_GetBtreeDepth(BTreeNode *root)
{
    int depth = 0;
    int left_depth = 0;
    int right_depth = 0;

    if (root != NULL)
    {
        left_depth = _GetBtreeDepth(root->lChild);
        right_depth = _GetBtreeDepth(root->rChild);

        depth = left_depth > right_depth ? left_depth : right_depth;
        return depth+1;
    }
    return 0;
}

/*
 *  从根结点开始,只要当前结点不空或者栈不空,重复执行一下操作
 *  若当前结点存在,将左孩子入栈;否则出栈并访问,然后将右孩子入栈
 */
void BTree::PreOrder()
{
    this->_PreOrder(root);
    cout << endl;
}

void BTree::_PreOrder(BTreeNode *root)
{
    BTreeNode *pTemp = root;
    stack<BTreeNode *> stackBTree;

    while (pTemp != NULL || !stackBTree.empty())
    {
        while (pTemp != NULL)
        {
            cout << pTemp->data << " ";
            stackBTree.push(pTemp);
            pTemp = pTemp->lChild;
        }

        pTemp = stackBTree.top();
        stackBTree.pop();
        pTemp = pTemp->rChild;
    }
}

/*
 * 用栈进行会朔
 * 每打印完一个结点,要对其右孩子进行处理
 * 每个结点都需要遍历找到最左边的孩子打印
 */
void BTree::MidOrder()
{
    this->_MidOrder(root);
    cout << endl;
}

void BTree::_MidOrder(BTreeNode *root)
{
    BTreeNode *pTemp = root;
    stack<BTreeNode *> stackBTree;

    while (pTemp != NULL || !stackBTree.empty())
    {
        while(pTemp != NULL)
        {
            stackBTree.push(pTemp);
            pTemp = pTemp->lChild;
        }

        pTemp = stackBTree.top();
        cout << pTemp->data << " ";
        stackBTree.pop();
        pTemp = pTemp->rChild;
    }
}

/*
 */

void BTree::PostOrder()
{
    this->_PostOrder(root);
    cout << endl;
}

void BTree::_PostOrder(BTreeNode *root)
{
    BTreeNode *pRoot = root;
    BTreeNode *pTemp = NULL;
    stack<BTreeNode*> stackBTree;

    while (pRoot != NULL || !stackBTree.empty())
    {
        while (pRoot != NULL)
        {
            stackBTree.push(pRoot);
            pRoot = pRoot->lChild;
        }

        if (!stackBTree.empty())
        {
            pRoot = stackBTree.top();

            if (pRoot->rChild == NULL || pTemp == pRoot->rChild)
            {
                cout << pRoot->data << " ";
                pTemp = pRoot;
                stackBTree.pop();
                pRoot = NULL;
            }
            else
            {
                pRoot = pRoot->rChild;
            }
        }
    }
}

//输出叶子结点可以用三种遍历方法中任意一中实现，只需要在输出时判断左右孩子是否为空
void BTree::OutPutLeaft()
{
    this->_OutPutLeaft(root);
    cout << endl;
}

void BTree::_OutPutLeaft(BTreeNode *root)
{
    if (root != NULL)
    {
        if (root->lChild == NULL && root->rChild == NULL)
        {
            cout << root->data << " ";
        }

        _OutPutLeaft(root->lChild);
        _OutPutLeaft(root->rChild);
    }
}

int BTree::GetNodeNum()
{
    return this->_GetNodeNum(root);
}

int BTree::_GetNodeNum(BTreeNode *root)
{
    if (NULL == root)
    {
        return 0;
    }

    return (1 + _GetNodeNum(root->lChild) + _GetNodeNum(root->rChild));
}

void BTree::LayerOrder()
{
    this->_LayerOrder(root);
    cout << endl;
}

void BTree::_LayerOrder(BTreeNode *root)
{
    if (root == NULL)
        return;

    queue<BTreeNode *> queueTree;
    BTreeNode *Temp = NULL;

    queueTree.push(root);
    while (!queueTree.empty())
    {
        Temp = queueTree.front();
        cout << Temp->data << " ";

        if (Temp->lChild)
            queueTree.push(Temp->lChild);

        if (Temp->rChild)
            queueTree.push(Temp->rChild);

        queueTree.pop();
    }
}

void BTree::CreateBtreeBYPreMid(string &pre_str, string &mid_str)
{
    int length = pre_str.length();
    if (pre_str.empty() || mid_str.empty() || length <= 0)
    {
        return ;
    }

    char value = pre_str[0];
    BTreeNode *root_node = new BTreeNode();
    root_node->data = value;
    root_node->lChild = root_node->rChild = NULL;

    int left_leaf = 0;
    int right_leaf = 0;
    int i = 0;

    while (i < length && mid_str[i] != value)
    {
        i++;
    }

    left_leaf = i;
    right_leaf = length - left_leaf - 1;
    cout << "BTree::CreateBtreeBYPreMid ---> left and right leaf num : " << left_leaf << " " << right_leaf << endl;

    if (left_leaf > 0)
        //root_node->lChild = CreateBtreeBYPreMid(pre_str+1, mid_str);

    if (right_leaf > 0)
        //root_node->rChild = CreateBtreeBYPreMid(pre_str+length-right_leaf, mid_str+length-right_leaf);

    root = root_node;
    delete root_node;
    root_node = NULL;
}

BTreeNode* BTree::GetMaxKValue(int value)
{
    BTreeNode *pRoot = root;
    if (pRoot == NULL)
        return NULL;

    stack<BTreeNode *> stackBTree;
    while (!stackBTree.empty() || pRoot)
    {
        if (pRoot)
        {
            stackBTree.push(pRoot);
            pRoot = pRoot->rChild;
        }
        else
        {
            pRoot = stackBTree.top();
            value--;
            
            if (value == 0)
            {
                return pRoot;
            }

            pRoot = pRoot->lChild;
            stackBTree.pop();
        }
    }
}

void BTree::GetDepthKNode(int k)
{
    this->_GetDepthKNode(root, k);
    cout << endl;
}

void BTree::_GetDepthKNode(BTreeNode *root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
    }
    _GetDepthKNode(root->lChild, --k);
    _GetDepthKNode(root->rChild, --k);
}

BTreeNode* BTree::GetParents(BTreeNode *node)
{
    return this->_GetParents(root, node);
}

BTreeNode* BTree::_GetParents(BTreeNode *root, BTreeNode *node)
{
    BTreeNode *pRoot = root;
    BTreeNode *pTemp = NULL;

    if (node == NULL)
        return NULL;

    if (pRoot || pRoot->lChild == node || pRoot->rChild == node)
    {
        return root;
    }

    pTemp = _GetParents(root->lChild, node);
    if (!pTemp)
    {
        pTemp = _GetParents(root->rChild, node);
    }
    return pTemp;
}
