#include<iostream>
#include "Sort.h"
using namespace std;

int main(void)
{
    Sort *sort_obj = new Sort();
    int arr[] = {1,3,5,7,9,2,4,6,8,0};
    int len = sizeof(arr) / sizeof(arr[0]);

    sort_obj->BubbleSort(arr, len);
    sort_obj->Print(arr, len);

    return 0;
}

