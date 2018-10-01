#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;

int main(void)
{
    list<int> ilist{1,2,3,4,5,6,7,8,0,9,1,2,3,4,5};

    auto num = find(ilist.rbegin(), ilist.rend(), 0);
    cout << *num << endl;

    return 0;
}
