#include<iostream>
using namespace std;

bool CheckLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return false;

    Node *fast = head;
    Node *slow = head;

    while(slow != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

Node *FindLoopStart(Node *head)
{
    if(head == NULL || head->next == NULL)
        return;

    Node *fast = head;
    Node *slow = head;

    while(slow != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow == NULL || fast->next == NULL)
        return NULL;

    Node *ptr1 = head; // start
    Node *ptr2 = slow; //相遇点

    while(ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1;
}
