#include <iostream>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;

int main(void)
{
    stack<int, list<int> > istack;

    istack.push(4);
    istack.push(5);
    istack.push(8);
    istack.push(1);
    istack.push(6);

    cout << istack.size() << endl;
    cout << istack.top() << endl;

    istack.pop();
    cout << istack.size() << endl;
    cout << istack.top() << endl;

    cout << istack.empty() << endl;

    return 0;
}
