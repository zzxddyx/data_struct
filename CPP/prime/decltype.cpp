#include<iostream>
using namespace std;

int add(int a, int b)
{
    return a+b;
}

int main(void)
{
    int a = 10;
    int b = 20;
    //int sum = add(a, b);
    //decltype(add(a, b)) sum = add(a, b);
    auto sum = add(a, b);
    cout << sum << endl;

    return 0;
}
