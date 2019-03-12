#include<iostream>
using namespace std;

bool duplicate1(int numbers[], int length, int* duplication)
{
    if (numbers == NULL || length < 0)
    {
        return false;
    }

    for (int i = 0; i < length; ++i)
    {
        while(numbers[i] != i)
        {
            if (numbers[i] == numbers[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            }

            int tmp = numbers[i];
            numbers[i] = numbers[tmp];
            numbers[tmp] = tmp;
        }
    }

    return false;
}

bool duplicate2(int numbers[], int len)
{
    if (numbers == NULL || len < 0)
    {
        return false;
    }

    int *arr = new int[len]();
    for (int i = 0; i < len; ++i)
    {
        ++arr[numbers[i]];

        if (arr[numbers[i]] > 1) {
            cout << "find this number : " << numbers[i] << endl;
            return true;
        }
    }
    return false;
}

int getCount(int *numbers, int len, int start, int end) 
{
    if (NULL == numbers || len < 0)
    {
        return -1;
    }

    int count = 0;
    for (int i = 0; i < len; ++i)
    {
        if (numbers[i] >= start && numbers[i] <= end)
        {
            count++;
        }
    }

    return count;
}

int duplicate3(int *numbers, int len) 
{
    int start = 1;
    int end = len - 1;

    while(start <= end) 
    {
        int middle = ((end - start) >> 1) + start;
        int count = getCount(numbers, len, start, middle);

        if (start == end)
        {
            if(count > 0)
            {
                return start;
            } 
            else 
            {
                break;
            }
        }

        if(count > (middle-start+1)) 
        {
            end = middle;
        }
        else
        {
            start = middle+1;
        }
    }

    return -1;
}

int main(void) 
{
    int arr[] = {2, 3, 1, 0, 2, 5, 3};
    int len = sizeof(arr)/sizeof(arr[0]);

    int num;
    bool result = false;
    //result = duplicate1(arr, len, &num);
    if (result) {
        cout << "find : " << num << endl;
    } 
    else
    {
       // cout << "not find" << endl;
    }

    //result = duplicate2(arr, len);
    //cout << "duplicate2" << endl;

    int res = duplicate3(arr, len);
    cout << res << endl;



    return 0;
}
