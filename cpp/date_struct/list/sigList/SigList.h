#ifndef _SIGLIST_H_
#define _SIGLIST_H_

#include <iostream>
#include "DataStruct.h"
using namespace std;

template<typename T>
class SigList
{
    public:
        SigList()
        {
        }
        ~SigList()
        {
            FreeList();
        }

    // typename
    public:
        void InsertHead(T &value)
        {
            DataStruct<T> *pNew = new DataStruct<T>;
            pNew->data = value;
            pNew->next = NULL;

            if (head == NULL)
            {
                head = pNew;
            }
            else
            {
                pNew->next = head;
                head = pNew;
            }
        }

        void InsertTail(T value)
        {
            DataStruct<T> *pNew = new DataStruct<T>;
            pNew->data = value;
            pNew->next = NULL;

            if (head == NULL)
            {
                head = pNew;
            }
            else
            {
                DataStruct<T> *pTmp = head;
                while( pTmp->next != NULL)
                {
                    pTmp = pTmp->next;
                }
                pTmp->next = pNew;
            }
        }

        void DeleteByValue(T &value)
        {
            DataStruct<T> *pValue = head;
            DataStruct<T> *pPrev = NULL;

            while (pValue != NULL)
            {
                while (pValue != NULL && pValue->data != value)
                {
                    pPrev = pValue;
                    pValue = pValue->next;
                }

                if (pValue == NULL)
                {
                    cout << "not found this valu : " << value << endl;
                    break;
                }

                if (pPrev == NULL) // del head
                {
                    DataStruct<T> *pNode = head;
                    head = pNode->next;
                    delete pNode;
                    pNode = NULL;
                }
                else
                {
                    pPrev->next = pValue->next;
                    delete pValue;
                    pValue = NULL;
                }
            }
        }

        DataStruct<T>* SearchValue(T &value)
        {
            DataStruct<T> *pNode = head;
            while (pNode != NULL)
            {
                cout << "in function SearchValue : " << value << " " << pNode->data << endl;
                if (pNode->data == value)
                {
                    return pNode;
                }
                pNode = pNode->next;
            }
            return NULL;
        }
    public:
        void Show()
        {
            DataStruct<T> *pPos = head;
            while (pPos != NULL)
            {
                cout << pPos->data << " ";
                pPos = pPos->next;
            }
            cout << endl;
        }

        void DeleteHead()
        {
            DataStruct<T> *pHead = head;
            if (pHead->next != NULL)
            {
                head = pHead->next;
                delete pHead;
                pHead = NULL;
            }
        }

        void DeleteTail()
        {
            DataStruct<T> *pHead = head;
            while (pHead->next != NULL)
            {
                pHead = pHead->next;
            }

            delete pHead;
            pHead = NULL;
        }

        bool isEmpty()
        {
            if (head)
            {
                return false;
            }
            return true;
        }

        void FreeList()
        {
            while (head)
            {
                DataStruct<T> *tmp_head = head;
                head = head->next();
                delete tmp_head;
            }
        }

        void Reverse1()
        {
            if (head == NULL || head->next == NULL)
            {
                return;
            }

            DataStruct<T> *p1 = head;
            DataStruct<T> *p2 = head->next;
            DataStruct<T> *p3 = NULL;
            head->next = NULL;

            while (p2 != NULL)
            {
                p3 = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = p3;
            }

            head = p1;
        }

        void Reverse(DataStruct<T> *p)
        {
            if (head == NULL || head->next == NULL)
            {
                return;
            }

            DataStruct<T> *pNew = Reverse(head->next);
            head->next->next = head;
            head->next = NULL;
            head = pNew;
        }

        void FanZhuan()
        {
            DataStruct<T> *p1 = head;
            DataStruct<T> *p2 = head->next;
            DataStruct<T> *p3 = NULL;
            head->next = NULL;

            while (p2 != NULL)
            {
                p3 = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = p3;
            }

            head = p1;
        }

        bool CheckHuan()
        {
            DataStruct<T> *pPos = head;
            if (pPos == NULL && pPos->next == NULL)
            {
                return false;
            }

            DataStruct<T> *slow = pPos->next;
            DataStruct<T> *fast = pPos->next->next;

            while (slow && fast)
            {
                if (slow == fast)
                {
                    return true;
                }
                slow = slow->next;
                fast = fast->next->next;
            }
            return false;
        }

        void DelIndexValue(int index)
        {
            if (index < 0)
            {
                return;
            }
            DataStruct<T> *pHead = new DataStruct<T>;
            pHead->next = head;
            DataStruct<T> *fast = pHead;
            DataStruct<T> *slow = pHead;
            
            while(fast != NULL && index >= 0)
            {
                fast = fast->next;
                index--;
            }

            while(fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }

            slow->next = slow->next->next;
            delete pHead;
            pHead = NULL;
        }

        void DeleSameValue()
        {
            if (NULL == head)
            {
                return;
            }

            DataStruct<T> *cur = head;
            DataStruct<T> *pre = head;

            while (cur != NULL)
            {
                if (cur->next != NULL && cur->data == cur->next->data)
                {
                    T same_value = cur->data;
                    while (cur->next != NULL && cur->next->data == same_value)
                    {
                        cur = cur->next;
                    }

                    pre->next = cur->next;
                }
                else
                {
                    pre = cur;
                }
                cur = cur->next;
            }
        }

        void DeleteSameValue1()
        {
            if (NULL == head)
            {
                return;
            }

            DataStruct<T> *pHead = new DataStruct<T>;
            pHead->next = head;
            DataStruct<T> *pre = pHead;
            DataStruct<T> *cur = head;
            DataStruct<T> *nxt = head->next;

            while (nxt != NULL)
            {
                while(nxt != NULL && cur->data == nxt->data)
                {
                    nxt = nxt->next;
                }

                // 有重复的元素
                if (cur->next != nxt)
                {
                    while (cur != nxt) // 删除元素
                    {
                        pre->next = cur->next;
                        delete cur;
                        cur = pre->next;
                    }
                    if (nxt != NULL)
                    {
                        nxt = nxt->next;
                    }
                }
                else // 没有重复的元素指针移动
                {
                    pre = cur;
                    cur = cur->next;
                    nxt = nxt->next;
                }
            }

            head = pHead->next;
            delete pHead;
            pHead = NULL;
        }

    private:
        DataStruct<T> *head;
};

#endif //_SIGLIST_H_
