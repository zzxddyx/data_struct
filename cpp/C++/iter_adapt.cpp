#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace std;

int main(void)
{
    int arr[] = {1,2,3,4,5,6,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    deque<int> id(arr, arr+len);

    copy(id.begin(), id.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    copy(id.begin(), id.begin()+3, front_inserter(id));
    copy(id.begin(), id.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    copy(id.begin(), id.begin()+3, back_inserter(id));
    copy(id.begin(), id.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    deque<int>::iterator iter = find(id.begin(), id.end(), 3);
    copy(id.begin(), id.begin()+3, inserter(id, iter));
    copy(id.begin(), id.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    copy(id.rbegin(), id.rend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
