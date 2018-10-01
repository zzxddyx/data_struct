#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main(void)
{
    /*  
    char buf1[] = "Hello";
    char buf2[] = "hello";

    if ( strcmp(buf1, buf2) == 0)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    */

    vector<string> v1{"Hello"};
    vector<string> v2{"hello"};

    if ( v1 == v2 )
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
