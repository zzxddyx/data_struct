#include <iostream>
#include <string>
#include <initializer_list>
#include <iterator>
using namespace std;

/*
void print1(const int *beg, const int *end)
{
    while( beg != end)
    {
        cout << *beg++ << endl;
    }
    cout << endl;
}

int main(void)
{
    int arr[] = { 1,2,3,4,5,6,7,8,9 };
    print1(begin(arr), end(arr));

    return 0;
}
*/

void sum(initializer_list<int> ii)
{
    auto sum = 0;
    for ( auto &i : ii)
    {
        sum += i;
    }
    cout << sum << endl;
}

int main(int argc, char *argv[])
{
    /*
    while(argv)
    {
        while(*argv)
        {
            cout << *argv++ << endl;
        }
    }
    */

    int arr[] = { 1,2,3,4,5,6,7 };
    sum({1,2,3,4,5});

    string s;
    for ( int i = 1; i < argc; ++i)
    {
        s += argv[i];
    }
    cout << s << endl;

    return 0;
}
