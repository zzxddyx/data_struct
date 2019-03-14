/*
#include "./list.h"
int main(void)
{
    ListNode *Head = NULL;

    InsertTail(&Head, 4);
    InsertTail(&Head, 5);
    InsertTail(&Head, 6);
    InsertTail(&Head, 7);
    InsertTail(&Head, 8);
    InsertTail(&Head, 9);

    Print(Head);
}
*/

/*
#include "./BinaryTree.h"

int main(void)
{
    BTree *pRoot;
    Create(&pRoot);

    Print(pRoot);

}
*/


#include "./ParentBTree.h"

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
    
    return 0;
}
