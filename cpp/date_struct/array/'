#include<iostream>
using namespace std;

/*
 * 1.判断输入的参数是否合法
 * 2.设置两个标识位,一个最大的一个次大的
 * 3.矫正两个标志位的值
 * 4.遍历整个数组,如果发现符合条件的重新复制
 */

int FindSecondMaxNum(int *arr, int length)
{
    if (NULL == arr or length < 2)
    {
        return 0xfffffff;
    }

    int max = arr[0];
    int second = arr[1];

    if (second > max)
    {
        max = arr[1];
        second = arr[0];
    }

    for ( int i = 2; i < length; ++i)
    {
        if (arr[i] > max)
        {
            second = max;
            max = arr[i];
        }
        else if (arr[i] > second)
        {
            second = arr[i];
        }
    }

    return second;
}

int FindSecondMinNum(int *arr, int length)
{
    if (NULL == arr or length < 2)
    {
        return 0xfffffff;
    }

    int min = arr[0];
    int second = arr[1];

    if (min > second)
    {
        min = arr[1];
        second = arr[0];
    }

    for (int i = 2; i < length; ++i)
    {
        if (arr[i] < min)
        {
            second = min;
            min = arr[i];
        }
        else if (arr[i] < second)
        {
            second = arr[i];
        }
    }

    return second;
}

int main(void)
{
    int arr[] = {12, -3, 4, 45, 90, 12, 89, 4};
    int length = sizeof(arr) / sizeof(arr[0]);

    int second = FindSecondMaxNum(arr, length);
    cout << "The Second Max Value is : " << second << endl;

    second = FindSecondMinNum(arr, length);
    cout << "The Second Min Value is : " << second << endl;

    return 0;
}
