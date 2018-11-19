#ifndef _SORT_H_
#define _SORT_H_

#include <iostream>
using namespace std;

class Sort
{
    public:
        void InsertSort(int *arr, int length);
        void BubbleSort(int *arr, int length);
        void BTreeSort(int *arr, int length);
        void CountSort(int *arr, int length, int *tmp);
        void RadixSort(int *arr, int length);

        void SelectSort(int *arr, int length);
        void QuicklSort(int *arr, int left, int right);
        void HeapSort(int *arr, int length);
        void MergeSort(int *arr, int left, int right, int *tmp);
        void ShellSort(int *arr, int length);

    public:
        void Swap(int &a, int &b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }

        void Print(int *arr, int length)
        {
            for (int i = 0; i < length; ++i)
            {
                cout << *(arr + i) << " ";
            }
            cout << endl;
        }
};

#endif //_SORT_H_

