#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>
using namespace std;

/*
int main(void)
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr)/sizeof(arr[0]);

    vector<int> iv(arr, arr+len);
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));

    int res = count_if(iv.begin(), iv.end(), not1(modulus<int>(), 2));
    cout << res << endl;

    return 0;
}
*/

int main(void)
{
    vector<int> iv;
    for (int i = 2; i < 15; ++i)
    {
        iv.push_back(i);
    }

    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    int count = count_if(iv.begin(), iv.end(), not1(bind2nd(less<int>(), 10)));
    cout << count << endl;

    return 0;
}
