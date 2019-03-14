#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
using namespace std;

int FindMinInArr(int *arr, int len)
{
    int min = arr[0];
    for (int i = 1; i < len; ++i)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

int minNum(int *arr, int len)
{
    if (arr == NULL || len <= 0)
    {
        cout << "error" << endl;
        return -1;
    }

    int start = 0;
    int end = len - 1;
    int index = start;

    while(arr[start] >= arr[end])
    {
        if(end-start == 1)
        {
            index = end;
            break;
        }

        index = (end+start) / 2;
        if (arr[start] == arr[end] && arr[start] == arr[index])
            return FindMinInArr(arr, len);

        if (arr[index] > arr[start])
            start = index;
        else if(arr[index] < arr[end])
            end = index;
    }

    return arr[index];
}

int main(void)
{
    int arr[] = {6,7,8,9,1,2,3,4,5};
    int len = sizeof(arr)/sizeof(arr[0]);

    int res = minNum(arr, len);
    cout << "=====" << res << endl;

    return 0;
}

