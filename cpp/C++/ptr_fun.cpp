#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <numeric>
using namespace std;

int main(void)
{
    char *foo[] = {"111", "22", "34", "55", "66"};
    int bar[5] = {};
    int sum = 0;

    transform(foo, foo+5, bar, ptr_fun(atoi));
    smm = accumulate(bar, bar+5, 0);
    cout << sum << endl;

    return 0;
}
