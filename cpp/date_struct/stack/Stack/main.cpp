#include "Stack.h"
#include <iostream>
using namespace std;

#define MAX_LEN 1024

int main(void)
{
    Stack<int> *my_stack = new Stack<int>(MAX_LEN);

    for (int i = 10; i < 100; ++i)
    {
        my_stack->Push(i);
    }

    cout << "stack size : " << my_stack->Size() << endl;
    cout << "stack empty : " << my_stack->isEmpty() << endl;
    cout << "stack top : " << my_stack->Top() << endl;

    while (! my_stack->isEmpty() )
    {
        cout << "stack pop value : " << my_stack->Pop() << endl;
    }
    cout << endl;

    return 0;
}
