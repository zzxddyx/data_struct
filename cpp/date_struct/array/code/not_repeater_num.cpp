#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

/*
int main(void)
{

    int arr[] = {1,23,99,34,34,23,1};
    int len = sizeof(arr) / sizeof(arr[0]);
    int result = arr[0];

    for (int i = 1; i < len; ++i)
    {
        result = result ^ arr[i];
    }

    cout << "get result is : " << result << endl;

    return 0;
}
*/

/*
 * 1. 根据数组建立顺序map，不排序
 * 2. 遍历map,找到第一个值为1的key
 */

int main(void)
{
    int arr[] = {99,3,23,99,34,34,23,1};
    int len = sizeof(arr) / sizeof(arr[0]);
    list<pair<int, int>> Map;

    for (int i = 0; i < len; ++i)
    {
        auto iter = find_if(Map.begin(), Map.end(), [&](const pair<int, int> &value){
                return value.first == arr[i];
        });

        if (iter != Map.end())
        {
            iter->second += 1;
        }
        else
        {
            Map.push_back(make_pair(arr[i], 1));
        }
    }

    auto iter = Map.begin();
    /*
    for (; iter != Map.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    */

    for (; iter != Map.end(); ++iter)
    {
        if (iter->second == 1)
        {
            cout << "find the first value : " << iter->first << endl; 
            return 0;
        }
    }

    cout << "not find value" << endl;

    return 0;
}
