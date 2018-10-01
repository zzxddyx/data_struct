#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main(void)
{
    list<int> li{0,1,2,3,4,5,6,7};
    deque<int> jdi;
    deque<int> odi;

    for (auto x : li)
    {
        if (x % 2)
        {
            jdi.push_back(x);
        }
        else
        {
            odi.push_back(x);
        }
    }

    for (auto x : jdi)
    {
        cout << x << endl;
    }

    for (auto x : odi)
    {
        cout << x << endl;
    }

    return 0;
}

