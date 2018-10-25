#include "Search.h"

bool Search::Search_Seq(int *arr, int length, int search_num)
{
    if(arr == NULL || length < 0)
        return false;

    for(int i = 0; i < length; ++i)
    {
        if (arr[i] == search_num)
            return true;
    }
    return false;
}

bool Search::Search_Bin(int *arr, int low, int high, int search_num)
{
    if (low > high)
        return false;

    int mid = (low + high) / 2;

    if (arr[mid] == search_num)
        return true;
    else if(search_num < arr[mid])
        return Search_Bin(arr, low, mid-1, search_num);
    else if(search_num > arr[mid])
        return Search_Bin(arr, mid+1, high, search_num);
}

void Search::Sort(int *arr, int len)
{
    cout << len << " " << len-1 << endl;
    this->Quick_Sort(arr, 0, len-1);
}

void Search::Quick_Sort(int *arr, int low, int high)
{
    if(low > high)
        return;

    int left = low;
    int right = high;
    int key = arr[low];

    while(left < right)
    {
        while(left < right && arr[right] > key)
            right--;
        arr[left] = arr[right];

        while(left < right &&  arr[left] < key)
            left++;
        arr[right] = arr[left];
    }

    arr[left] = key;
    Quick_Sort(arr, low, left-1);
    Quick_Sort(arr, left+1, high);
}
