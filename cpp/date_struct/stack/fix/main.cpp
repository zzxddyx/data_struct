#include <iostream>
#include <string>
#include "./Fix.h"
using namespace std;

int main(void)
{
    Fix fix;
    string calc_str = "9-(4+6) * 2"; //
    cout << fix.GetResult(calc_str) << endl;

    return 0;
}

