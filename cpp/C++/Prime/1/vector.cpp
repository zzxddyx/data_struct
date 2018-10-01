#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <iterator>
using namespace std;

int main(void)
{
    /*  
    vector<string> vs{ 10, "Hello" };

    cout << vs.size() << endl;
    for (auto v : vs)
    {
        cout << v << endl;
    }
    cout << endl;
    */

    /*
    vector<int> v;
    for (auto i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }

    for (unsigned int i = 0, j = v.size()-1; i < j; i++, j--)
    {
        cout << v[i] << ' ' << v[j] << endl;
        cout << v[i] + v[j] << endl;
    }

    vector<int> v;//1,2,3,4,5,6,7,8,9);
    for (auto i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }
    for (auto iter = v.begin(); iter != v.end(); ++iter )
    {
        *iter *= 2;
    }

    for (auto x : v)
    {
        cout << x << endl;
    }
    */

    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int *p = arr;
    for (auto i = begin(arr); i < end(arr); ++i)
    {
        *p = 0;
    }

    for (auto x : arr)
    {
        cout << x << endl;
    }

    return 0;
}
