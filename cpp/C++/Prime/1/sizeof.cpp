#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    /*
     * 指针类型所占大小为8个字节
     */
    /*  
    int arr[] = {1,2,3,4,5,6,7};
    auto *p = arr;
    cout << *p << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(*p) << endl;
    cout << sizeof(p) << endl;
    */

    int arr[10];
    auto *p = arr;

    cout << sizeof(arr) / sizeof(*arr) << endl;
    cout << sizeof(p) / sizeof(*p) << endl;




    return 0;
}
