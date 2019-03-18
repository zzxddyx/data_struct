/*************************************************************************
    > File Name: verifyBTree.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月18日 星期一 08时40分36秒
 ************************************************************************/

#include <iostream>
using namespace std;

bool checkBST(int *arr, int len)
{
    if(arr == NULL || len <= 0)
        return false;

    int root = arr[len-1];

    int i = 0;
    for(; i < len-1; ++i)
    {
        if(arr[i] > root)
            break;
    }

    int j = i;
    for(; j < len-1; ++j)
    {
        if(arr[j] < root)
            return false;
    }

    bool left = true;
    if (i > 0)
        left = checkBST(arr, i);

    bool right = true;
    if (i < len - 1)
        right = checkBST(arr, len-i-1);

    return left && right;
}

int main(void)
{
    int arr1[] = {5,7,6,9,11,10,8};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);

    int arr2[] = {7,4,6,5};
    int len2 = sizeof(arr2)/sizeof(arr2[0]);

    cout << checkBST(arr1, len1) << endl;
    cout << checkBST(arr2, len2) << endl;

    return 0;
}
