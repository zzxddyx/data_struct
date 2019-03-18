#include <iostream>
#include <stack>
using namespace std;

//在该栈中，调用min、push及pop的时间复杂度都是O(1)。
template<typename T>
class MinStack
{
    public:
        MinStack()
        {
        }
        ~MinStack()
        {
        }

    public:
        void push(const T &value)
        {
            mData.push(value);

            if(mMin.empty() || value < mMin.top())
                mMin.push(value);
            else
                mMin.push(mMin.top());
        }

        void pop()
        {
            mData.pop();
            mMin.pop();
        }

        T& min()
        {
            return mMin.top();
        }

    private:
        stack<T> mData;
        stack<T> mMin;
};

int main(void)
{
    MinStack<int> s;

    s.push(3);
    s.push(2);
    s.push(4);
    s.push(8);
    s.push(1);

    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.pop();

    return 0;
}
