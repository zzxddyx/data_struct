#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<iostream>
using namespace std;

/*
 * 1.入队:tail++
 * 2.出队:head++
 */

class Queue
{
    public:
        Queue(int size);
        ~Queue();

    public:
        bool Enqueue(int value);
        bool Dequeue();
        bool isEmpty();
        int GetTop();

    private:
        int m_QueueCapaticy; // 总大小
        int m_QueueSize;     // 实际size
        int m_QueueHead;     // 头
        int m_QueueTail;     // 尾
        int* m_pQueue;       // 起始指针
        bool CheckSize();
};

#endif

