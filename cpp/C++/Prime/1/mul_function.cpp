#include <iostream>
using namespace std;

int calcx(int a, int b)
{
    cout << a + b << endl;
}
int calc(const int a, const int b)
{
    cout << a + b << endl;
}

/*
auto func(int i) -> int (*)[10]
{
    cout << i << endl;
    int arr[10] = {};
    for (int j = 0; j < 10; ++j)
    {
        arr[j] = i;
    }
    return &arr;
}
*/

/*
 * string (&func())[10]
 *
 * - 类型别名
 * typedef string arrS[10];
 * arrS& func();
 *
 * - 尾置类型
 * auto func() -> string (&)[10];
 *
 * - decltype
 * string [10]arr = {};
 * decltype(arr) &func()
 */

int main(void)
{
    typedef int fuck;
    using cc = int;
    fuck jj = 10;
    cc dd = 50;
    cout << jj << ' ' << dd << endl;

    return 0;
}
