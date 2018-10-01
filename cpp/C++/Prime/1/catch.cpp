#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;

int main(void)
{
    int a, b;
    int count = 0;
    cout << "Enter num : " << endl;

    while (cin >> a >> b)
    try
    {
        if (a < 0 or b < 0)
        {
            throw runtime_error("num < 0\n");
        }
        count = a + b;
        cout << count << endl;
    }
    catch(runtime_error err)
    {
        cout << err.what() << "Try Again (y or n)" << endl;
        char c;
        cin >> c;

        if ( !cin || c == 'n' || c == 'N')
        {
            break;
        }
    }

    return 0;
}
