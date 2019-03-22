/*************************************************************************
    > File Name: main.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月22日 星期五 07时56分27秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
using namespace std;

void Print(int *arr, int len)
{
    for (int i = 0; i < len; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void Swap(int *num1, int *num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int randomIndex(int start, int end)
{
    int index = rand() % (end-start+1) + start;
    return index;
}

int Paration(int *arr, int len, int start, int end)
{
    if (NULL == arr || len <= 0 || start < 0 || end >= len)
        return -1;

    int index = start;
    Swap(&arr[index], &arr[end]);

    int small = start-1;
    for (int i = start; i < end; ++i)
    {
        if (arr[i] < arr[end])
        {
            ++small;
            if(i != small)
                Swap(&arr[i], &arr[small]);
        }
    }

    ++small;
    Swap(&arr[small], &arr[end]);
    return small;
}

void FindNumofn(int *arr, int len, int k, int start, int end)
{
    if(arr == NULL || len <= 0 || k < 0 || start < 0 || end >= len)
        return;

    int index = Paration(arr, len, start, end);
    while (index != k-1)
    {
        if (index > k-1)
        {
            end=index-1;
            index = Paration(arr, len, start, end);
        }
        else
        {
            start = index+1;
            index = Paration(arr, len, start, end);
        }
    }

    Print(arr, k);
}

void GetMinNumofN(vector<int> &arr, multiset<int, greater<int>> &minSet, int k)
{
    minSet.clear();

    if(arr.size() <= 0 || k < 1 || arr.size() < k)
        return;

    vector<int>::iterator iter = arr.begin();
    for (; iter != arr.end(); ++iter)
    {
        if(minSet.size() < k)
            minSet.insert(*iter);
        else
        {
            multiset<int, greater<int>>::iterator vIter = minSet.begin();
            if (*vIter > *iter)
            {
                minSet.erase(vIter);
                minSet.insert(*iter);
            }
        }
    }

    multiset<int, greater<int>>::iterator setIter = minSet.begin();
    for (; setIter != minSet.end(); ++setIter)
        cout << *setIter << " ";
    cout << endl;
}



int main(void)
{
    int arr[] = {4,5,1,6,2,7,3,8};
    int len = sizeof(arr)/sizeof(arr[0]);
    Print(arr, len);

    int start = 0;
    int end = len-1;
    int k = 4;

    //FindNumofn(arr, len, k, start, end);
    vector<int> vArr(arr, arr+len);
    multiset<int, greater<int>> set;
    GetMinNumofN(vArr, set, 4);


    return 0;
}
