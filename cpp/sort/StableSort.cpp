#include "Sort.h"

/*
 * 1.比较相邻的元素,如果后一个元素比前一个元素大,则调换位置
 * 2.这样一遍下来,最后一个元素是最大的
 * 3.排除最后一个数,重复执行1.2
 *  时间复杂度为O(n2)
 */
void Sort::BubbleSort(int *arr, int length)
{
    /*
    for (int i = 0; i < length; ++i)
    {
        for (int j = i + 1; j < length; ++j)
        {
            if (arr[i] > arr[j])
            {
                this->Swap(arr[i], arr[j]);
            }
        }
    }
    */
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; i < length - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                this->Swap(arr[j], arr[j+1]);
            }
        }
    }
}
