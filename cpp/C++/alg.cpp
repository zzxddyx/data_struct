#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

template<typename T>
struct display
{
    void operator()(const T& v) const
    {
        cout << v << " ";
    }
};

struct even
{

};

int main(void)
{
    int arr[] = {1,2,3,3,4,5,6,6,6,7,8,9,3};
    int len = sizeof(arr)/sizeof(arr[0]);

    vector<int> iv(arr, arr+len);

    //找出iv中相邻元素值相等的第一个元素
    cout << *adjacent_find(iv.begin(), iv.end()) << endl;
    cout << *adjacent_find(iv.begin(), iv.end(), equal_to<int>()) << endl;

    cout << count(iv.begin(), iv.end(), 6) << endl;


    return 0;
}
