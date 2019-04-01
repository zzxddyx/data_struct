#include<iostream>
using namespace std;

void Print(int *arr, int len)
{
    for (int i = 0; i < len; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main(void)
{
    int arr[] = {2,4,6,8,0,1,3,5,7,9};
    int len = sizeof(arr)/sizeof(arr[0]);

    Print(arr, len);

    for (int i = 1; i < len; ++i)
    {
        for (int j = 0; j < len-i-1; ++j)
        {
            if (arr[j+1] < arr[j])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    Print(arr, len);

    return 0;
}
