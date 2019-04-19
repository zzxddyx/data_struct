#include<iostream>
using namespace std;

void InsertSoct(int *arr, int len)
{
    if (NULL == arr || len <= 0)
        return;

    for (int i = 1; i < len; ++i)
    {
        int key = arr[i];
        int preIndex = i - 1;
        
        while(preIndex >= 0 && arr[preIndex] > key)
        {
            arr[preIndex+1] = arr[preIndex];
            preIndex--;
        }
        arr[preIndex+1] = key;
    }
}

void Print(const int *arr, int len)
{
    if (NULL == arr || len <= 0)
        return;

    for (int i = 0; i < len; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main(void)
{
    int arr[] = {0,8,6,4,2,1,3,5,7,9};
    int len = sizeof(arr)/sizeof(arr[0]);

    Print(arr, len);
    InsertSoct(arr, len);
    Print(arr, len);


    return 0;
}
