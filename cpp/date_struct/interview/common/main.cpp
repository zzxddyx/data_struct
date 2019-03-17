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


/*
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
*/

/*
#include "./List.h"
int main(void)
{
    ListNode *p1 = CreateNode(1);
    ListNode *p2 = CreateNode(2);
    ListNode *p3 = CreateNode(3);
    ListNode *p4 = CreateNode(4);
    ListNode *p5 = CreateNode(5);
    ListNode *p6 = CreateNode(6);

    ConnectListNode(p1, p2);
    ConnectListNode(p2, p3);
    ConnectListNode(p3, p4);
    ConnectListNode(p4, p5);
    ConnectListNode(p5, p6);

    Print(p1);
}
*/

#include "./BTree.h"

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

    return 0;
}
