/*************************************************************************
    > File Name: recordArray.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月17日 星期日 10时35分36秒
 ************************************************************************/

#include <iostream>
using namespace std;

void ReSortArray(int *arr, int len)
{
    if (arr == NULL || len <= 0)
        return;

    int *start = arr;
    int *end = arr+len-1;

    while(start < end)
    {
        while(start < end && (*start & 0x01) != 0)
            start++;

        while(start < end && (*end & 0x01) == 0)
            end--;

        if(start < end)
        {
            int tmp = *start;
            *start = *end;
            *end = tmp;
        }
    }
}

void Print(int *arr, int len)
{
    for (int i = 0; i < len; ++i)
        cout << *(arr+i) << " ";
    cout << endl;
}

int main(void)
{
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int len = sizeof(arr)/sizeof(arr[0]);

    Print(arr, len);
    ReSortArray(arr, len);
    Print(arr, len);

    return 0;
}
