#include <iostream>
#include <algorithm>
using namespace std;

int fun(const int &a, const int &b)
{
    auto sum = [a](int b){ return a+b; };
    return sum(b);
}

int main(void)
{
    int sum = fun(19, 15);

    cout << sum << endl;

    return 0;
}
