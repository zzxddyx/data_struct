/*************************************************************************
    > File Name: isNumeric.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月16日 星期六 18时48分36秒
 ************************************************************************/

#include <iostream>
using namespace std;

bool isNumber(const char **str)
{
    const char *start = *str;
    while(**str != '\0' && **str >= '0' && **str <= '9')
    {
        ++(*str);
    }
    return *str > start;
}

bool isNumeric(const char **str)
{
    if((**str) == '+' || (**str) == '-')
    {
        ++(*str);
    }

    return isNumber(str);
}

bool isDigit(const char *str)
{
    if (str == NULL)
        return false;

    bool digit = isNumeric(&str);

    if(*str == '.')
    {
        ++str;

        digit = digit || isNumber(&str);
    }
    if (*str == 'e' || *str == 'E')
    {
        ++str;

        digit = digit && isNumeric(&str);
    }

    return digit && *str == '\0';
}

int main(void)
{
    const char *str1 = "+100";
    const char *str2 = "-1E-16";
    const char *str3 = "12e";
    const char *str4 = "12e+5.4";

    cout << isDigit(str1) << endl;
    cout << isDigit(str2) << endl;
   cout << isDigit(str3) << endl;
    cout << isDigit(str4) << endl;

    return 0;
}


