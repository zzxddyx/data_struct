#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main(void)
{
    vector<int> arr0{1,2,3,4,5};
    vector<int> arr1{1,2,3,4,5,6};
    list<int> arr2{1,2,3,4,5, 10};

    vector<int> tmp(arr2.begin(), arr2.end());

    if (arr0 == tmp)
    {
        cout << "==" << endl;
    }
    else if (arr0 < tmp)
    {
        cout << "<" << endl;
    }
    else
    {
        cout << ">" << endl;
    }

    return 0;
}
