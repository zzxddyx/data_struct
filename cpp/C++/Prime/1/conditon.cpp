#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>
using namespace std;

int main(void)
{
    vector<int> v{1,2,3,4,5,6,7,8,9,0};

    for ( auto &x : v)
    {
        x % 2 == 1 ? x *= 2 : x;
    }

    for ( const auto &x : v)
    {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}
