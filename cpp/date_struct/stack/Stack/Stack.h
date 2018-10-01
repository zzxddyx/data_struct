#ifndef _STACK_H_
#define _STACK_H_

#include<iostream>
using namespace std;

template <class T>
class Stack
{
    public:
        Stack(int len);
        ~Stack();
    public:
        void Push(const T& value);
        T& Pop();
        bool isEmpty();
        T& Top();
        int Size();

    private:
        int stack_size;
        T* arr;
};

template<class T>
Stack<T>::Stack(int len)
{
    arr = new int[len];
    stack_size = 0;
    if (!arr)
    {
        cout << "new stack size error" << endl;
    }
}

template<class T>
Stack<T>::~Stack()
{
    if (arr)
    {
        delete []arr;
        arr = NULL;
    }
    stack_size = 0;
}

template<class T>
void Stack<T>::Push(const T& value)
{
    arr[stack_size] = value;
    stack_size++;
}

template<class T>
T& Stack<T>::Pop()
{
    T& value = arr[stack_size-1];
    stack_size--;
    return value;
}

template<class T>
int Stack<T>::Size()
{
    return stack_size;
}

template<class T>
bool Stack<T>::isEmpty()
{
    return this->Size() == 0;
}

template<class T>
T& Stack<T>::Top()
{
    return arr[stack_size-1];
}
#endif // _STACK_H_
