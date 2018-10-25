#include<iostream>
using namespace std;

bool FindMin(int *arr, int len)
{
    int start = 0;
    int end = len;

    while(start < end)
    {
        int mid = (start + end)/2;
        if(arr[start]  < arr[mid])
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
    }

    int min = arr[start] < arr[end] ? arr[start] : arr[end];
    cout << "iiii" << min << endl;
    return true;
}

int main(void)
{
    int arr[] = {3,4,5,6,7,0,1,2};
    int len = sizeof(arr)/sizeof(arr[0]);

    bool find = FindMin(arr, len);
    cout << find << endl;

    return 0;

}
