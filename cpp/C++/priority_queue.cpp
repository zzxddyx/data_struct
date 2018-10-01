#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
    int arr[] = {1,3,5,7,8,0,8,5,3};
    int len = sizeof(arr)/sizeof(arr[0]);

    priority_queue<int> iqueue(arr, arr+len);

    for(int i = 0; i < iqueue.size(); ++i)
    {
        cout << iqueue.top() << " , ";
    }
    cout << endl;

    while(!iqueue.empty())
    {
        cout << iqueue.top() << ",";
        iqueue.pop();
    }
    cout << endl;

    return 0;
}
