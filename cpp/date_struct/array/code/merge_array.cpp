#include <iostream>
#include <cstring>
using namespace std;

#define ARR_MAX_LEN 100

void GetLen(int *arr, int &len)
{
    while(*arr != 0)
    {
        ++len;
        ++arr;
    }
}

int *MergeArrayToNew(int *arr1, int *arr2, int len1, int len2)
{
    if (arr1 == NULL || arr2 == NULL || len1 <= 0 || len2 <= 0)
    {
        return NULL;
    }

    int index1 = 0; // array 1 index
    int index2 = 0; // array 2 index
    int index = 0;  // new array index
    int *arrTemp = new int[len1 + len2];

    while (index1 < len1 && index2 < len2)
    {
        if (arr1[index1] < arr2[index2])
        {
            arrTemp[index++] = arr1[index1++];
        }
        else
        {
            arrTemp[index++] = arr2[index2++];
        }
    }

    while (index1 < len1)
    {
        arrTemp[index++] = arr1[index1++];
    }

    while (index2 < len2)
    {
        arrTemp[index++] = arr2[index2++];
    }

    return arrTemp;
}

void MergeArrayToOld(int *arr1, int *arr2, int len1, int len2)
{
    if (arr1 == NULL || arr2 == NULL || len1 <= 0 || len2 <= 0 || (len1 + len2 > ARR_MAX_LEN))
    {
        return;
    }

    int new_len = len1 + len2 - 1;
    int new_len1 = len1 - 1;
    int new_len2 = len2 - 1;

    while (new_len1 >= 0 && new_len2 >= 0)
    {
        if (arr1[new_len1] > arr2[new_len2])
        {
            arr1[new_len--] = arr1[new_len1--];
        }
        else
        {
            arr1[new_len--] = arr2[new_len2--];
        }
    }

    while(new_len1 >= 0)
    {
        arr1[new_len--] = arr1[new_len1--];
    }

    while(new_len2 >= 0)
    {
        arr1[new_len--] = arr2[new_len2--];
    }
}


int main(void)
{
    int arr1[ARR_MAX_LEN] = {1,3,5,7,9,11,45};
    int arr2[ARR_MAX_LEN] = {2,4,6,8,10,13,34,99};

    int len1 = 0;
    int len2 = 0;
    GetLen(arr1, len1);
    GetLen(arr2, len2);

    cout << "array length : " << len1 << " " << len2 << " " << endl;

    /*
    int *result = MergeArrayToNew(arr1, arr2, len1, len2);
    for (int i = 0; i < len1 + len2; ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    delete []result;
    */

    MergeArrayToOld(arr1, arr2, len1, len2);
    for (int i = 0; i < len1+len2; ++i)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    return 0;
}

