#include <iostream>
using namespace std;

int main(void)
{
    int i = 34;
    int &ir = i;
    int &&r = ir*4;

    cout << i << ' ' << ir << ' ' << r << endl;

    return 0;
}
