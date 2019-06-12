#include "list.h"

NODE *create(int n) // 创建
{
    NODE *pNew = new NODE();
    pNew->data = n;
    pNew->next = NULL;

    return pNew;
}

void connect(NODE *pcur, NODE *pnext) // 结点链接
{
    if(pcur == NULL)
        return;

    pcur->next = pnext;
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
}

NODE *insert(NODE *phead, int data) // 结点的插入
{
    if(phead == NULL)
    {
    }
}

NODE *delets(NODE *phead, int pos) // 结点删除
{

}

NODE *reverse(NODE *phead) // 翻转
{

}

NODE *search_mid(NODE *phead) // 寻找中间元素
{
}

NODE *sort(NODE *phead) // 排序
{


}

bool isLoop(NODE *phead, NODE **start) // 判断是否有环
{

}

NODE *merge(NODE *phead1, NODE *phead2) // 两个有序链表合并
{

}

