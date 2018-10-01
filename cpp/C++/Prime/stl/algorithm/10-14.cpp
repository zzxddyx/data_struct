#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    auto add = [](const int &a, const int &b){ return a+b; };

    cout << add(10,20) << endl;

    return 0;
}
