#ifndef _DOB_LIST_H_
#define _DOB_LIST_H_

#include<iostream>
using namespace std;

template <typename T>
struct NODE
{
    T data;
    struct NODE *prev;
    struct NODE *next;
};

template <typename T>
class DobList
{
    public:
        DobList()
        {
        };
        ~DobList()
        {
        };

    public:
        void InsertHead(T &value)
        {
            NODE<T> *pNew = new NODE<T>;
            pNew->data = value;
            pNew->prev = NULL;
            pNew->next = head;

            if (head != NULL)
            {
                head->prev = pNew;
            }

            head = pNew;
        }

        void InsertTail(T &value)
        {
            if (head == NULL)
            {
                InsertHead(value);
            }
            else
            {

                NODE<T> *pNew = new NODE<T>;
                NODE<T> *pPos = head;
                pNew->data = value;
                pNew->next = NULL;

                while (pPos->next != NULL)
                {
                    pPos = pPos->next;
                }

                pPos->next = pNew;
                pNew->prev = pPos;
            }
        }

        void DeleteByValue(T value)
        {
            NODE<T> *pPos = head;
            if (pPos == NULL)
            {
                return;
            }

            while (pPos != NULL)
            {
                while (pPos != NULL && pPos->data != value)
                {
                    pPos = pPos->next;
                }

                if (pPos == NULL)
                {
                    break;
                }

                if (pPos->prev == NULL && pPos->next != NULL)
                {
                    DeleteByHead();
                }
                else
                {
                    pPos->next->prev = pPos->prev;
                    pPos->prev->next = pPos->next;

                    delete pPos;
                    pPos = NULL;
                }
            }
        }

        void DeleteByHead()
        {
            if (head != NULL)
            {
                NODE<T> *pPos = head;
                head = pPos->next;
                pPos->prev = NULL;

                delete pPos;
                pPos = NULL;
            }
        }

        void DeleteByTail()
        {
            if (NULL == head || NULL == head->next)
            {
                DeleteByHead();
            }
            else
            {
                NODE<T> *pPos = head;
                while (pPos->next != NULL)
                {
                    pPos = pPos->next;
                }

                pPos->prev->next = NULL;
                delete pPos;
                pPos = NULL;
            }
        }

        int SearchByValue(T value)
        {
            if (NULL == head)
            {
                return -1;
            }

            NODE<T> *pPos = head;
            while (pPos != NULL)
            {
                while(pPos != NULL && pPos->data != value)
                {
                    pPos = pPos->next;
                }

                return pPos->data;
            }

            return -1;
        }

        bool isEmpty()
        {
            if (head)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        void FreeList()
        {
            while(head != NULL)
            {
                DeleteByTail();
            }
        }

        void Show()
        {
            NODE<T> *pPos = head;
            while (pPos)
            {
                cout << pPos->data << " ";
                pPos = pPos->next;
            }
            cout << endl;
        }

    private:
        NODE<T> *head;
};

#endif //_DOB_LIST_H_
