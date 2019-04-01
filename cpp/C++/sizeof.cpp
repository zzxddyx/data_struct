#include<iostream>
using namespace std;

int main(void)
{
    int arr[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
    };

    cout << sizeof(arr) << endl;
    cout << arr+1 << endl;

    return 0;
}
