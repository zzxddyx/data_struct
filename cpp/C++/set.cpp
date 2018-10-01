#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(void)
{
    int arr[] = {3,5,23,6,2,3,8,345};
    int len = sizeof(arr)/sizeof(arr[0]);
    set<int> iset(arr, arr+len);

    set<int>::iterator iter = iset.begin();
    for(; iter != iset.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "set size : " << iset.size() << endl;
    //iset.clear();
    //cout << "set size : " << iset.size() << endl;
    cout << iset.count(3) << endl;
    cout << iset.count(9) << endl;

    iter = iset.upper_bound(23);
    cout << *iter << endl;
    cout << iset.max_size() << endl;


    return 0;
}
