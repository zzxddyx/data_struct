#include<iostream>
#include <queue>
#include <stack>
using namespace std;

void Show(queue<int> &q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void RevertQueue(queue<int> &q)
{
    stack<int> s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty())
    {
        cout << "1" << endl;
        q.push(s.top());
        s.pop();
    }
    Show(q);
}

int main(void)
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    RevertQueue(q);

    return 0;
}

