#include <iostream>
#include "BTree.h"
using namespace std;

int main(void)
{
    BTree *root = new BTree();
    string left = "ABD##E#F##C##";
    string num = "532##4##76##8##";

    root->CreateBTree();
    cout << "traverse is : " << endl;
    root->PreOrderTraverse();
    root->MidOrderTracerse();
    root->PostOrderTracerse();
    cout << "normal output is : " << endl;
    root->PreOrder();
    root->MidOrder();
    root->PostOrder();
    cout << "layer output is : " << endl;
    root->LayerOrder();

    //cout << "left node is : " << root->OutPutLeaft() << endl;
    //cout << "node num is : " << root->GetNodeNum() << endl;

    //root->DestoryBTree();
    //root->DestoryBTree_Queue();
    //root->PostOrderTracerse();

    BTreeNode *result = NULL;
    //result = root->ByValueGetNode('B');
    //cout << "by value get node result is : " << result->data << endl;
    //result = root->FindParents(result);
    //cout << "find node parents result is : " << result->data << endl;
    //result = root->GetLeftChild(result);
    //cout << "get left child result is : " << result->data << endl;
    //result = root->GetRightChile(result);
    //cout << "get right child result is : " << result->data << endl;
    //cout << "btree depth is : " << root->GetBTreeDepth() << endl;

    //string pre_str = "ABDEFC";
    //string mid_str = "DBEFAC";
    //root->CreateBtreeBYPreMid(pre_str, mid_str);
    //root->PreOrderTraverse();

    result = root->GetMaxKValue(6);
    cout << "get max k value is : " << result->data << endl;

    cout << "by depth k get node is : ";
    root->GetDepthKNode(1);

    return 0;
}
