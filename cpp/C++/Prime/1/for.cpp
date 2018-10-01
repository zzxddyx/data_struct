#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(void)
{
    /*
    int arr[][3] = {1,2,3,4,5,6,7,8,9};

    for ( auto i = begin(arr); i != end(arr); ++i)
    {
        for ( auto j = begin(*i); j != end(*i); ++j)
        {
            cout << *j << ' ';
        }
        cout << endl;
    }
    cout << endl;
    */
    vector<int> v{23,45,23,78,65,12};
    for ( auto iter = v.begin(); iter != v.end(); ++iter )
    {
        cout << *iter << endl;
    }

    cout << "===========================" << endl;
    cout << *(v.begin()) << endl;
    cout << *v.begin() + 1 << endl;


    return 0;
}

