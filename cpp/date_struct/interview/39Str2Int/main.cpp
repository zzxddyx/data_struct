/*************************************************************************
    > File Name: main.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月25日 星期一 21时53分45秒
 ************************************************************************/

#include <iostream>
using namespace std;

enum Status 
{
    kValid = 0,
    kInvalid
};

int g_nStatus = kValid;

long long StrToIntCore(char *str, bool minus)
{
    long long num = 0;
    while(*str != '\0')
    {
        if (*str >= '0' && *str <= '9')
        {
            int flag = minus ? -1 : 1;
            num = num *10 + flag*(*str-'0');

            if((!minus && num > 0x7FFFFFFF) || (minus && num < 0x80000000))
            {
                num = 0;
                break;
            }

            str++;
        }
        else
        {
            num = 0;
            break;
        }
    }

    if(*str == '\0')
    {
        g_nStatus = kValid;
    }

    return num;
}

int StrToInt(char *str)
{
    g_nStatus = kInvalid;
    long long num = 0;

    if (str != NULL && *str != '\0')
    {
        bool minus = false;
        if (*str == '+')
            str++;
        else if (*str == '-')
        {
            minus = true;
            str++;
        }

        if (*str != '\0')
            num = StrToIntCore(str, minus);
    }

    return (int)num;
}

int main(void)
{
    char str[] = "1234";

    int val = StrToInt(str);

    cout << val << endl;

    return 0;
}
