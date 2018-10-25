#ifndef SEARCH_H_
#define SEARCH_H_

#include<iostream>
using namespace std;

class Search
{
    public:
        bool Search_Seq(int *arr, int len, int search_num);
        bool Search_Bin(int *arr, int low, int high, int search_num);
    public:
        void Print(int *arr, int len)
        {
            for (int i = 0; i < len; ++i)
                cout << *(arr + i) << " ";
            cout << endl;
        }
        void Sort(int *arr, int length);
        void Quick_Sort(int *arr, int low, int high);
};

#endif //SEARCH_H_

