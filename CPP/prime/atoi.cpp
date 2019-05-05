#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
    char str[1024] = "12345";

    auto res = atoi(str);
    cout << res << endl;

    return 0;
}
