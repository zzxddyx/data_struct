#include "Queue.h"

Queue::Queue(int size)
    :m_QueueCapaticy(size), m_QueueSize(0), m_QueueHead(0), m_QueueTail(0)
{
    m_pQueue = new int[size];
}

Queue::~Queue()
{
    if (m_pQueue != NULL)
    {
        delete []m_pQueue;
        m_pQueue = NULL;
    }
}

bool Queue::CheckSize()
{
    if(this->m_QueueSize < this->m_QueueCapaticy)
    {
        return true;
    }
    return false;
}

bool Queue::Enqueue(int value)
{
    if(!this->CheckSize())
    {
        cout << __FILE__ << " : " << __LINE__ << " : " << __FUNCTION__ << " : " << "failed" << endl;
        return false;
    }

    m_pQueue[m_QueueTail] = value;
    m_QueueTail++;
    m_QueueTail = m_QueueTail % m_QueueCapaticy;
    m_QueueSize++;
    return true;
}

bool Queue::Dequeue()
{
    if (this->m_QueueSize == 0)
    {
        cout << __FILE__ << " : " << __LINE__ << " : " << __FUNCTION__ << " : " << "failed" << endl;
        return false;
    }

    int value = m_pQueue[m_QueueHead];
    cout << "Queue head is : " << value << endl;
    m_QueueHead = m_QueueHead++;
    m_QueueHead = m_QueueHead % m_QueueCapaticy;
    return true;
}

bool Queue::isEmpty()
{
    return this->m_QueueSize == 0;
}

int Queue::GetTop()
{
    if(this->isEmpty())
    {
        return 0xffffffff;
    }

    int value = this->m_pQueue[this->m_QueueHead];
    this->m_QueueHead--;
    this->m_QueueHead = this->m_QueueHead % this->m_QueueCapaticy;
    return value;
}
