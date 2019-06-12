#include "list.h"

NODE *create(int n) // 创建
{
    NODE *pNew = new NODE();
    pNew->data = n;
    pNew->next = NULL;

    return pNew;
}

void connect(NODE *pCur, NODE *pNext) // 结点链接
{
    if(pCur == NULL)
        return;

    pCur->next = pNext;
}

void print(NODE *phead) // 打印
{
    while(phead != NULL)
    {
        std::cout << phead->data << " ";
        phead = phead->next;
    }
    std::cout << std::endl;
}

int length(NODE *phead) // 求长度
{
    int len = 0;
    while(phead != NULL)
    {
        len++;
        phead = phead->next;
    }
    return len;
}

NODE *search(NODE *phead, int pos) // 但链表结点的查找
{
    NODE *pTmp = phead;
    int len = length(pTmp);
    if (pos > len)
        return NULL;

    int index = 1;
    while(pTmp != NULL)
    {
        if (index == pos)
            return pTmp;

        pTmp = pTmp->next;
        index++;
    }
    return NULL;
}

NODE *insert(NODE *phead, int data) // 结点的插入
{
    NODE *pNew = new NODE();
    pNew->data = data;
    pNew->next = NULL;

    if(phead == NULL)
    {
        phead = pNew;
        phead->next = NULL;
    }
    else
    {
        NODE *pTmp = phead;
        while(pTmp->next != NULL)
            pTmp = pTmp->next;
        pTmp->next = pNew;
    }
    return phead;
}

NODE *delets(NODE *phead, int pos) // 结点删除
{
    int len = length(phead);
    if(pos > len)
        return phead;

    NODE *pPre = phead;
    NODE *pCur = phead;

    if(pos == 1)
    {
        pCur = phead->next;
        delete phead;
        phead = NULL;
        return pCur;
    }

    for(int i = 1; i < pos; ++i)
    {
        pPre = pCur;
        pCur = pCur->next;
    }

    pPre->next = pCur->next;
    delete pCur;
    pCur = NULL;

    return phead;
}

NODE *reverse(NODE *phead) // 翻转
{
    if(phead == NULL)
        return NULL;

    NODE *pNewHead = NULL;
    NODE *pCur = phead;
    NODE *pPre = NULL;

    while(pCur != NULL)
    {
        NODE *pNext = pCur->next;
        if(pNext == NULL)
            pNewHead = pCur;

        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
    }

    return pNewHead;
}

NODE *search_mid(NODE *phead) // 寻找中间元素
{
    if(phead == NULL || phead->next == NULL)
        return phead;

    NODE *slow = phead;
    NODE *fast = phead;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
    }

    return slow;
}

NODE *sort(NODE *phead) // 排序
{
    if(phead == NULL || phead->next == NULL)
        return phead;

    for(NODE *p1 = phead; p1 != NULL; p1 = p1->next)
    {
        for(NODE *p2 = p1->next; p2 != NULL; p2 = p2->next)
        {
            if(p2->data < p1->data)
            {
                int tmp = p1->data;
                p1->data = p2->data;
                p2->data = tmp;
            }
        }
    }

    return phead;
}

NODE *isLoop(NODE *phead) // 判断是否有环
{
    if(phead == NULL || phead->next == NULL)
        return NULL;

    NODE *pslow = phead;
    NODE *pfast = phead->next;

    while(pfast != NULL && pfast->next != NULL)
    {
        if(pslow == pfast)
            return pslow;

        pslow = pslow->next;
        pfast = pfast->next;
        if(pfast->next != NULL)
            pfast = pfast->next;
    }
    return NULL;
}

NODE *loopStart(NODE *phead)
{
    if(phead == NULL || phead->next == NULL)
        return phead;

    NODE *loop = isLoop(phead);
    if(loop == NULL)
        return NULL;

    // 找出环中的个数
    int count = 1;
    NODE *meet = loop;
    while(meet != loop->next)
    {
        ++count;
        loop = loop->next;
    }

    // 两个指针找到入口
    NODE *p1 = phead;
    for(int i = 0; i < count; ++i)
        p1 = p1->next;
        
    NODE *p2 = phead;
    while(p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

NODE *merge(NODE *phead1, NODE *phead2) // 两个有序链表合并
{
    if(phead1 == NULL && phead2 == NULL)
        return NULL;

    if(phead1 == NULL)
        return phead2;

    if(phead2 == NULL)
        return phead1;

    NODE *pHead = NULL;
    if(phead1->data < phead2->data)
    {
        pHead = phead1;
        pHead->next = merge(phead1->next, phead2);
    }
    if(phead1->data > phead2->data)
    {
        pHead = phead2;
        pHead->next = merge(phead1, phead2->next);
    }

    return pHead;
}

NODE *mergeInsert(NODE *head, NODE *node)
{
    NODE *pPre = head;
    NODE *pCur = head;

    while(pCur != NULL && pCur->data <= node->data)
    {
        pPre = pCur;
        pCur = pCur->next;
    }

    if(pCur == head)
    {
        node->next = pCur;
        return node;
    }
    else
    {
        pPre->next = node;
        node->next = pCur;
        return head;
    }
}

NODE *mergeList(NODE *phead1, NODE *phead2)
{
    if(phead1 == NULL || phead2 == NULL)
        return NULL;

    if(phead1 == NULL)
        return phead2;

    if(phead2 == NULL)
        return phead1;

    NODE *newHead = NULL;
    NODE *pTmp = NULL;

    int len1 = length(phead1);
    int len2 = length(phead2);

    if(len1 >= len2)
    {
        newHead = phead2;
        pTmp = phead1;
    }
    else
    {
        newHead = phead1;
        pTmp = phead2;
    }

    NODE *pPos = NULL;
    while(pTmp != NULL)
    {
        pPos = pTmp->next;
        newHead = mergeInsert(newHead, pTmp);
        pTmp = pPos;
    }

    return newHead;
}

