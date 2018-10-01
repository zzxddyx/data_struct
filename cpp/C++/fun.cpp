#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
#include <numeric>
using namespace std;

int main(void)
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(arr)/sizeof(arr[0]);
    vector<int> iv(arr, arr+len);

    //do (v+2)*3
    for_each(iv.begin(), iv.end(), std::compose1(bind2nd(multiplies<int>(), 3), bind2nd(plus<int>(), 2)));
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
