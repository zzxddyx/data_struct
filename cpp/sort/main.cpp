#include<iostream>
#include "Sort.h"
using namespace std;

int main(void)
{
    Sort *sort_obj = new Sort();
    int arr[] = {1,3,5,7,9,2,4,6,8,0};
    int len = sizeof(arr) / sizeof(arr[0]);

    //sort_obj->BubbleSort(arr, len);
    //sort_obj->QuicklSort(arr, 0, len);
    //sort_obj->InsertSort(arr, len);
    //sort_obj->ShellSort(arr, len);
    //sort_obj->SelectSort(arr, len);
    //sort_obj->HeapSort(arr, len);
    //sort_obj->MergeSort(arr, len);
    //sort_obj->CountSort(arr, len);
    //sort_obj->BucketSort(arr, len, 5);
    sort_obj->RadixSort(arr, len);
    sort_obj->Print(arr, len);

    return 0;
}

