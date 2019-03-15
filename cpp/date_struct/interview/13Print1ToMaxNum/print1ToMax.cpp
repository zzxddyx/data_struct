/*************************************************************************
    > File Name: print1ToMax.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月15日 星期五 07时48分28秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

void PrintMaxNum1(int n)
{
    if (n <= 0)
        return;

    int index = 0;
    int num = 1;
    while(index < n)
    {
        num *= 10;
        index++;
    }

    for (index = 1; index < num; index++)
        cout << index << endl;
}

bool Increment(char *number)
{
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = strlen(number);

    for (int i = nLength-1; i>=0; --i)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength-1)
            nSum++;

        if(nSum >= 10)
        {
            if(i == 0)
            {
                isOverflow = true;
            }
            else 
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = nSum + '0';

            }
        }
        else 
        {
            number[i] = nSum + '0';
            break;
        }
    }

    return isOverflow;
}

void PrintNumber(const char *number)
{
    if (number == NULL)
        return;

    int len = strlen(number);
    bool isZero = true;
    for (int i = 0; i < len; ++i)
    {
        if (isZero && number[i] != '0')
            isZero = false;

        if(!isZero)
            cout << number[i];
    }
    cout << "\t";
}

void PrintMaxNum(int n)
{
    if (n <= 0)
        return;

    char *number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';

    while(!Increment(number))
        PrintNumber(number);

    delete[] number;
}

void printToMaxNumRecy(char *number, int n, int index)
{
    if (index == n-1)
    {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        number[index+1] = i+'0';
        printToMaxNumRecy(number, n, index+1);
    }
}

void PrintMaxNum2(int n)
{
    if (n <= 0)
        return;

    char *number = new char[n+1]();
    number[n] = '\0';

    for (int i = 0; i < 10; ++i)
    {
        number[0] = i+'0';
        printToMaxNumRecy(number, n, 0);
    }
}

int main(void)
{
    int n = 4;
    PrintMaxNum2(n);

    return 0;
}
