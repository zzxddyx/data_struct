/*
 * constexpr
 * inline
 * assert
 */

#include <iostream>
#include <cassert>
using namespace std;

int main(void)
{
    int a, b;
    cout << " Enter a and b :" << endl;
    cin >> a >> b;
    assert(b > 0);

    cout << a / b << endl;


    return 0;
}
