#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<int> vec{0,1,2,3,4,5,6,7,8,9};

    copy(vec.rbegin(), vec.rend(), ostream_iterator<int>(cout, " "));

    return 0;
}
