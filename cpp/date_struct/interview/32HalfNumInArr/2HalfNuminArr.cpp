/*************************************************************************
    > File Name: 2HalfNuminArr.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月21日 星期四 08时41分55秒
 ************************************************************************/

#include <iostream>
using namespace std;

bool checkOK(int *arr, int len, int num)
{
    if (arr == NULL || len <= 0)
        return false;

    int times = 0;
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] == num)
            times++;
    }

    return (times*2 > len);
}

int findHalfNum(int *arr, int len)
{
    if (arr == NULL || len <= 0)
        return 0;

    int num = arr[0];
    int times = 1;
    for (int i = 1; i < len; ++i)
    {
        if (arr[i] == num)
            times++;
        else if (times == 0)
        {
            num = arr[i];
            times = 1;
        }
        else
            times--;
    }

    if (!checkOK(arr, len, num))
        num = 0;

    return num;
}


int main(void)
{
    int arr[] = {1,2,3,2,2,2,5,4,2};
    int len = sizeof(arr)/sizeof(arr[0]);

    int res = findHalfNum(arr, len);
    cout << res << endl;

    return 0;
}
