#include <iostream>
#include <queue>
using namespace std;

void ReverseQueue(queue<int> &q)
{
    queue<int> tmp_q;
    int old_size = q.size();
    
    while(old_size > 0)
    {
        int max = q.front();
        q.pop();
        int count = old_size - 1;
        while (count > 0)
        {
            int cur_value = q.front();
            q.pop();

            if (cur_value < max) // > <
            {
                q.push(max);
                max = cur_value;
            }
            else
            {
                q.push(cur_value);
            }
            count--;
        }

        tmp_q.push(max);
        old_size--;
    }

    q = tmp_q;
}

int main(void)
{
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(3);
    q.push(6);
    q.push(8);
    q.push(7);
    q.push(9);
    q.push(1);

    ReverseQueue(q);

    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

