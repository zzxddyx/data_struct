#include <iostream>
#include <stack>
using namespace std;

void SortStack(stack<int> &input_stack)
{
    stack<int> temp_stack;

    while(!input_stack.empty())
    {
        int cur_value = input_stack.top();
        input_stack.pop();

        while(!temp_stack.empty() && cur_value < temp_stack.top())
        {
            input_stack.push(temp_stack.top());
            temp_stack.pop();
        }
        temp_stack.push(cur_value);
    }

    while(!temp_stack.empty())
    {
        int val = temp_stack.top();
        input_stack.push(val);
        temp_stack.pop();
    }
}

int main(void)
{
    stack<int> cur_stack;

    cur_stack.push(9);
    cur_stack.push(7);
    cur_stack.push(8);
    cur_stack.push(5);
    cur_stack.push(6);

    SortStack(cur_stack);

    while(!cur_stack.empty())
    {
        cout << cur_stack.top() << " ";
        cur_stack.pop();
    }
    cout << endl;

    return 0;
}

