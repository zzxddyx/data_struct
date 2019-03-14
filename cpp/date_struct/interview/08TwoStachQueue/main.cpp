#include "./queue.h"

int main(void)
{
    Queue<int> stack;

    stack.append(1);
    stack.append(2);
    stack.append(3);


    cout << stack.deleteHead() << endl;

    return 0;
}
