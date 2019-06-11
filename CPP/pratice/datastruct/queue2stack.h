#ifndef _QUEUE2STACK_H_
#define _QUEUE2STACK_H_

#include <iostream>
#include <queue>

template<typename T>
class MyStack
{
    public:
        MyStack();
        ~MyStack();

    public:
        void push(const T &value);
        T& pop();
        bool empty();
        int size();
    private:
        std::queue<T> q1;
        std::queue<T> q2;
};

#endif //_QUEUE2STACK_H_
