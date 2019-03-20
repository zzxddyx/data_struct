/*************************************************************************
  > File Name: Array.h
  > Author: BernieZhao
  > Mail: berniezhao@ezfun.cn
  > Created Time: 2019年03月20日 星期三 08时09分19秒
 ************************************************************************/

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
#include <cstdlib>
using namespace std;

#include <iostream>
#include <cstdlib>
using namespace std;

int RandomInRange(int start, int end)
{
    int random = rand() % (end - start + 1) + start;
    cout << random << endl;
    return random;
}

void Swap(int *num1, int *num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int Partition(int *arr, int length, int start, int end)
{
    if (arr == nullptr || end <= 0 || start < 0 || end >= length)
    {
        cout << "error" << endl;
        return -100;
    }

    int index = RandomInRange(start, end);
    Swap(&arr[index], &arr[end]);

    int small = start - 1;
    for (index = start; index < end; ++index)
    {
        if (arr[index] < arr[end])
        {
            ++small;
            if (small != index)
            {
                Swap(&arr[index], &arr[small]);
            }
        }
    }

    ++small;
    Swap(&arr[small], &arr[end]);
    return small;
}

#endif //_ARRAY_H_
