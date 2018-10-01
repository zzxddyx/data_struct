#include <iostream>
using namespace std;

static int i = 0;
struct Test
{
    Test()
    {
        ++i;
    }
    int value = i;
};

void f(Test s)
{
    cout << s.value << endl;
}

int main(void)
{
    Test a, b = a, c = b;
    Test d;

    f(a);
    f(b);
    f(c);
    f(d);

    return 0;
}


