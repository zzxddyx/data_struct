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

#include "./BinaryTree.h"

int main(void)
{
    BTree *pRoot;
    Create(&pRoot);

    Print(pRoot);

}
