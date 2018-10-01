#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/*
void add(int a, int b)
{
    cout << a+b << endl;
}

void add(double a, double b)
{
    cout << a+b << endl;
}

void add(int a, double b)
{
    cout << a+b << endl;
}

void fuck(long a)
{
    cout << a << endl;
}

void fuck(float a)
{
    cout << a << endl;
}
*/

int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int mul(int a, int b)
{
    return a*b;
}

int divv(int a, int b)
{
    assert(b > 0);
    return a/b;
}

int main(void)
{
    int x = 10;
    int y = -20;

    typedef int (*pf)(int, int);
    vector<pf> vp;


    pf Add = add;
    pf Sub = sub;
    pf Mul = mul;
    pf Div = divv;

    vp.push_back(Add);
    vp.push_back(Sub);
    vp.push_back(Mul);
    vp.push_back(Div);


    for (int iter = 0; iter < vp.size(); ++iter)
    {
        cout << vp[iter](x, y) << endl;
    }

    return 0;
}
