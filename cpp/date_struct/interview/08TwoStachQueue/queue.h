#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class Queue
{
    public:
        Queue(void);
        ~Queue(void);

        void append(const T &node);
        T deleteHead();

    private:
        stack<T> stack1; //push
        stack<T> stack2; //pop
};

template<typename T> 
Queue<T>::Queue(void)
{}

template<typename T> 
Queue<T>::~Queue(void)
{}

template<typename T> 
void Queue<T>::append(const T &node)
{
    stack1.push(node);
}

template<typename T>
T Queue<T>::deleteHead()
{
    if(stack2.size() <= 0)
    {
        while(!stack1.empty())
        {
            T &value = stack1.top();
            stack1.pop();
            stack2.push(value);
        }
    }

    if (stack2.size() == 0)
        cout << "error" << endl;

    T data = stack2.top();
    stack2.pop();

    return data;
}

#endif //_QUEUE_H_
