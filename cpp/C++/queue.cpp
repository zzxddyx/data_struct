#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

int main(void)
{
    queue<int, list<int> > iqueue;
    iqueue.push(4);
    iqueue.push(7);
    iqueue.push(6);
    iqueue.push(2);
    iqueue.push(8);
    iqueue.push(3);

    cout << iqueue.size() << endl;
    cout << iqueue.front() << endl;
    cout << iqueue.back() << endl;

    iqueue.pop();
    cout << iqueue.size() << endl;
    cout << iqueue.front() << endl;
    cout << iqueue.back() << endl;
    cout << iqueue.empty() << endl;

    iqueue.pop();
    iqueue.pop();
    iqueue.pop();
    iqueue.pop();
    iqueue.pop();
    cout << iqueue.empty() << endl;


    return 0;
}
