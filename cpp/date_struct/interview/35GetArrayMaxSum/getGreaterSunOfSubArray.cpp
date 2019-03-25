/*************************************************************************
    > File Name: getGreaterSunOfSubArray.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月24日 星期日 19时33分49秒
 ************************************************************************/

#include <iostream>
using namespace std;

bool gThrowBad = false;

int getMaxNumOfSubArray(int *arr, int len)
{
    if (arr == NULL || len <= 0)
    {
        gThrowBad = true;
        return 0;
    }

    gThrowBad = false;

    int curMaxSum = 0;
    int maxGreaterSum = 0x80000000;
    for (int i = 0; i < len; ++i)
    {
        if (curMaxSum <= 0)
            curMaxSum = arr[i];
        else
            curMaxSum += arr[i];

        if (curMaxSum > maxGreaterSum)
            maxGreaterSum = curMaxSum;
    }

    return maxGreaterSum;
}


int main(void)
{
    int arr[] = {1,-2,3,10,-4,7,2,-5};
    int len = sizeof(arr)/sizeof(arr[0]);

    int sum = getMaxNumOfSubArray(arr, len);
    cout << sum << endl;

    return 0;
}
