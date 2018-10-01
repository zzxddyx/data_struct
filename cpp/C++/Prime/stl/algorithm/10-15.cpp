#include <iostream>
#include <algorithm>
using namespace std;

auto add(const int &a, const int &b)
{
    auto sum = [a](int b){ return a+b; };
    return sum(b);
}

int main(void)
{
    cout << add(10, 20) << endl;


    return 0;
}
