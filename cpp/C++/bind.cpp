#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
using namespace std;

int main(void)
{
    vector<int> iv;
    iv.push_back(1);
    iv.push_back(4);
    iv.push_back(101);
    iv.push_back(59);
    iv.push_back(100);
    iv.push_back(190);

    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    //删除小于100
    //iv.erase(remove_if(iv.begin(), iv.end(), bind2nd(less<int>(), 100)), iv.end());
    //删除大于100
    //iv.erase(remove_if(iv.begin(), iv.end(), bind1st(less<int>(), 100)), iv.end());
    //删除大于100
    //iv.erase(remove_if(iv.begin(), iv.end(), bind2nd(greater<int>(), 100)), iv.end());
    //删除小于100
    iv.erase(remove_if(iv.begin(), iv.end(), bind1st(greater<int>(), 100)), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
