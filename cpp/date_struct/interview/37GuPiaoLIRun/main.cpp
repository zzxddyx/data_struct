/*************************************************************************
    > File Name: main.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月25日 星期一 21时29分52秒
 ************************************************************************/

#include <iostream>
using namespace std;

int MaxDiff(int *arr, int len)
{
    if (arr == NULL || len < 2)
        return -1;

    int min = arr[0];
    int maxDiff = arr[1] - min;

    for (int i = 2; i < len; ++i)
    {
        if (arr[i-1] < min)
        {
            min = arr[i-1];
        }

        int curDiff = arr[i] - min;
        if(curDiff >= maxDiff)
            maxDiff = curDiff;
    }

    return maxDiff;
}

int main(void)
{
    int arr[] = {9,11,8,5,7,12,16,14};
    int len = sizeof(arr)/sizeof(arr[0]);

    int x = MaxDiff(arr, len);
    cout << x << endl;

    return 0;
}
