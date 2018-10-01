#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main(void)
{
    string s("*Hello C++ !!");

    /* 
    for (auto &x : s)
    {
        if (isalnum(x))
            x = 'X';
    }

    for (int i = 0; i < s.size() - 1; ++i)
    {
        if (isalnum(s[i]))
        {
            s[i] = 'X';
        }
    }
    */

    cout << s << endl;

    return 0;
}
