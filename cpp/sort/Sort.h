#ifndef _SORT_H_
#define _SORT_H_

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Sort
{
    public:
        void InsertSort(int *arr, int length);
        void BubbleSort(int *arr, int length);
        void CountSort(int *arr, int length);
        void RadixSort(int *arr, int length);
        void BucketSort(int *arr, int length, int size);

        void SelectSort(int *arr, int length);
        void QuicklSort(int *arr, int left, int right);
        void HeapSort(int *arr, int length);
        void MergeSort(int *arr, int length); // 归并排序
        void ShellSort(int *arr, int length); // 希尔排序

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

    private:
        void BigHeadAdjust(int *arr, int index, int length);
        void Spera(int *arr, int left, int right);
        void Merge(int *arr, int left, int mid, int right);
        int  GetGroupCount(int value, int size, int min, int max);

        int GetRadixCount(int value);
        int GetTenRadixCount(int value);
};

#endif //_SORT_H_

