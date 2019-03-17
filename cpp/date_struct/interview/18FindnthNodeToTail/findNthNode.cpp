/*************************************************************************
    > File Name: findNthNode.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月17日 星期日 10时57分18秒
 ************************************************************************/

#include <iostream>
#include "../common/List.h"
using namespace std;

ListNode *findNode(ListNode *head, unsigned int n)
{
    if (head == NULL || n <= 0)
        return NULL;

    ListNode *start = head;
    ListNode *after = head;

    for (int i = 0; i < n-1; ++i)
    {
        if(start->next != NULL)
            start = start->next;
        else
            return NULL;
    }

    while(start->next != NULL)
    {
        start = start->next;
        after = after->next;
    }

    return after;
}


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
    cout << "====================" << endl;
    ListNode *res = findNode(p1, 2);
    cout << res->data << endl;

    return 0;
}
