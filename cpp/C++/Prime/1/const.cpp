#include <iostream>
using namespace std;

int num()
{
    return 40;
}

int main(void)
{
    const int i = num();
    cout << i << endl;
    return 0;
}
