#include<iostream>
#include <queue>
using namespace std;

template <class T>
class MyStack
{
    public:
        MyStack(){};
        ~MyStack(){};

    public:
        void Push(T &value)
        {
            // 首先放队列1
            if (IsEmpty())
            {
                q1.push(value);
            }
            else if (!q1.empty())
            {
                q1.push(value);
            }
            else
            {
                q2.push(value);
            }
        }

        T& Pop()
        {
            if (IsEmpty())
            {
                return;
            }
            else if (!q1.empty())
            {
                while(q1.size() > 1)
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                q1.pop();
            }
            else
            {
                while(!q2.size() > 1)
                {
                    q1.push(q2.front());
                    q2.pop();
                }
                q2.pop();
            }
        }

        T& Top()
        {
            if (!q1.empty())
            {
                return q1.back();
            }
            else
            {
                return q2.back();
            }
        }

        bool IsEmpty()
        {
            if (q1.empty() && q2.empty())
            {
                return true;
            }
            return false;
        }
    private:
        queue<T> q1;
        queue<T> q2;
};

int main(void)
{
    MyStack<int> my_stack;
    cout << my_stack.IsEmpty() << endl;

    for (int i = 10; i < 20; ++i)
    {
        my_stack.Push(i);
    }
    cout << my_stack.Top() << endl;

    return 0;
}
