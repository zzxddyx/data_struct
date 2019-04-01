#include<iostream>
using namespace std;

void Print(int *arr, int len)
{
    for (int i = 0; i < len; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void QuickSortCore(int *arr, int left, int right)
{
    if (left > right)
        return;

    int low = left;
    int high = right;
    int key = arr[low];

    while(low < high)
    {
        while(low < high && arr[high] >= key)
            high--;
        arr[low] = arr[high];

        while(low < high && arr[low] <= key)
            low++;
        arr[high] = arr[low];
    }

    arr[low] = key;
    QuickSortCore(arr, low+1, right);
    QuickSortCore(arr, left, low-1);
}

void QuickSort(int *arr, int len)
{
    if (NULL == arr || len < 0)
        return;

    int left = 0;
    int right = len-1;

    QuickSortCore(arr, left, right);
}

int main(void)
{
    int arr[] = {8,6,4,2,0,9,7,5,3,1};
    int len = sizeof(arr)/sizeof(arr[0]);

    Print(arr, len);
    QuickSort(arr, len);
    Print(arr, len);

    return 0;
}
