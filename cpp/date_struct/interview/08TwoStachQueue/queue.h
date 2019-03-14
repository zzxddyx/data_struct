/*************************************************************************
    > File Name: queue.h
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月14日 星期四 08时37分27秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Queue
{
    public;
    Queue(void);
    ~Queue(void);

    void append(const T &node);
    T deleteHead();

    private;
    stack<T> stack1;
    stack<T> stack2;
};
