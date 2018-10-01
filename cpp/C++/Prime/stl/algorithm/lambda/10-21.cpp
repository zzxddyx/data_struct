#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int sz;
    cin >> sz;

    auto fun = [&sz]() -> bool
    {
        if ( sz == 0 )
        {
            return true;
        }
        else
        {
            while(sz)
            {
                --sz;
            }
            return true;
        }
    };

    cout << fun() << endl;


    return 0;
}
