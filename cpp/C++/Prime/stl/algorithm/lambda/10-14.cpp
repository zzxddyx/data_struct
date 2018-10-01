#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    auto fun = [](int a, int b)
    { return a+b ;};

    cout << fun(1,2) << endl;

    return 0;
}
