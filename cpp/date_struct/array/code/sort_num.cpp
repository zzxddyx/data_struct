#include <iostream>
#include <cstring>
using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//O(n2)
void SortNum(int *arr, int len)
{
    /*
     * 1.找到负数的个数
     * 2.遍历数组,如果当前数所在位置小于负数的个数并且当前值为正将后面数向前挪,将该数放在数组的最后
     */
    if (!arr || len < 0)
    {
        return;
    }

    int nega_num = 0;
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] < 0)
        {
            nega_num += 1;
        }
    }

    int temp_value = 0;
    for (int i = 0; i < len; ++i)
    {
        if (i < nega_num)
        {
            while (arr[i] > 0)
            {
                temp_value = arr[i];
                for (int j = i+1; j < len; ++j)
                {
                    arr[j-1] = arr[j];
                }
                arr[len-1] = temp_value;
            }
        }
        else
        {
            break;
        }
    }
}

void SortNum1(int *arr, int len)
{
    if (! arr || len < 1)
    {
        return;
    }

    int low = 0;
    int hig = len - 1;

    while (low < hig)
    {
        while (arr[low] < 0 && low < hig)
        {
            low++;
        }

        while (arr[hig] > 0 && low < hig)
        {
            hig--;
        }

        Swap(arr[low], arr[hig]);
    }
}

void SortNum2(int *arr, int len)
{
    if (!arr || len < 1)
    {
        return;
    }

    int *start = arr;
    int *finsh = arr;
    int *pos = finsh;

    while (start < arr + len)
    {
        if (*start < 0)
        {
            Swap(*start, *finsh);
            pos = finsh;

            while (pos < start)
            {
                ++pos;
                Swap(*pos, *start);
            }
            ++finsh;
        }
        ++start;
    }
}

void SortNum3(int *arr, int len)
{
    if (!arr || len < 1)
    {
        return;
    }

    int *temp = new int[len];
    int nega_num = 0;
    int plus_num = 0;

    for (int i = 0; i < len; ++i)
    {
        if (arr[i] < 0)
        {
            temp[nega_num++] = arr[i];
        }
    }

    plus_num = len - nega_num;
    if (plus_num <= 0)
    {
        return;
    }

    plus_num = 0;
    for(int i = 0; i < len; ++i)
    {
        if (arr[i] >= 0)
        {
            temp[nega_num + plus_num] = arr[i];
            plus_num++;
        }
    }

    memcpy(arr, temp, sizeof(arr[0])*len);
    delete []temp;
}

int main(void)
{
    // -1,-3,-5,-7,-9,-99,2,4,6,8,23
    int arr[] = {-1,2,-3,4,-5,6,-7,8,-9,23,-99};
    int len = sizeof(arr) / sizeof(arr[0]);

    //SortNum(arr, len);
    //SortNum1(arr, len);
    //SortNum2(arr, len);
    SortNum3(arr, len);

    for (int i = 0; i < len; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
