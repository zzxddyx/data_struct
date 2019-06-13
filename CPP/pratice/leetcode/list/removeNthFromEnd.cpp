
/*
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 */

/*  
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/


class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(NULL == head)
                return NULL;

            ListNode *pFront = head;
            for(int i = 1; i < n; ++i)
                pQuick = pQuick->next;

            ListNode *pAfter = head;
            ListNode *pTmp = NULL:
            while(pFront != NULL)
            {
                pFront = pFront->next;
                pTmp = pAfter;
                pAfter = pAfter->next;
            }

            if (head == pAfter)
            {
                ListNode *pTmp = head->next;
                delete head;
                head = pTmp;
            }
            else
            {
                pTmp->next = pTmp->next->next;
            }
            return head;
        }
};

