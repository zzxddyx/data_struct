#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(void)
{
    vector<int> vi{1,2,3,4,56,6};
    for (auto x : vi)
    {
        cout << x << ' ';
    }
    cout << endl;

    list<int> li(vi.begin(), vi.end());
    for (auto &x : li)
    {
        x += 10;
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}


