#include <iostream>
using namespace std;

int main(void)
{
    /*
    int _or = 1;
    cout << _or << endl;

    int i = 100;
    int j = i;
    cout << i << " " << j << " " << ::i << endl;

    int k = 100, sum = 0;
    for (int k = 0; k != 10; ++k)
    {
        sum += k;
    }

    cout << k << ' ' << sum << endl;

    int i = 10, &vi = i;
    double d = 1.34, &vd = d;
    cout << i << ' ' << vi << endl;
    cout << d << ' ' << vd << endl;
    vi = 20.4;
    vd = vi;
    cout << i << ' ' << vi << endl;
    cout << i << ' ' << vi << ' ' << d << ' ' << vd << endl;
    */

    int i, &vi = i;
    cout << i << ' ' << vi << endl;


    return 0;
}
