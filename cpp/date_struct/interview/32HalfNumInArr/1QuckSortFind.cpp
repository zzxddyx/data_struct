/*************************************************************************
    > File Name: 1QuckSortFind.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月20日 星期三 08时05分26秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

int RandomIndex(int start, int end)
{
    int index = rand()%(end-start+1)+start;
    return index;
}

void Swap(int *num1, int *num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int Partation(int *arr, int len, int start, int end)
{
    if (arr == NULL || len <= 0 || start < 0 || end >= len)
        return -1;

    int index = RandomIndex(start, end);
    Swap(&arr[index], &arr[end]);

    int small = start - 1;
    for(int i = start; i < end; ++i)
    {
        if (arr[i] < arr[end])
        {
            ++small;
            if (i != small)
                Swap(&arr[small], &arr[i]);
        }
    }

    ++small;
    Swap(&arr[small], &arr[end]);
    return small;
}

bool checkOK(int *arr, int len, int num)
{
    int times = 0;
    for (int i = 0; i < len; ++i)
    {
        if(arr[i] == num)
            ++times;
    }

    return (times*2 > len);
}

int main(void)
{
    int arr[] = {1,2,3,2,2,2,5,4,2};
    int len = sizeof(arr)/sizeof(arr[0]);

    int mid = len >> 1;
    int start = 0;
    int end = len - 1;
    int index = Partation(arr, len, start, end);

    while(index != mid)
    {
        if (index > mid)
        {
            end = index - 1;
            index = Partation(arr, len, start, end);
        }
        else
        {
            start = index + 1;
            index = Partation(arr, len, start, end);
        }
    }

    int result = arr[index];
    if (checkOK(arr, len, result))
        cout << "ok " << result << endl;

    return 0;
}
