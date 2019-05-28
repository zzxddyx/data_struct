#include <iostream>
#include <cstdio>

int myStrlen(const char* str)
{
    int count = 0;
    if(str == NULL)
        return count;

    while(*str++ != '\0')
        ++count;

    return count;
}

void stoi(const char* str, int &res)
{
    if (str == NULL)
        res = 0;

    /*
    int len = myStrlen(str);
    int index = 0;
    bool negative = false;
    if (str[0] == '-')
    {
        negative = true;
        index = 1;
    }

    for (; index < len; ++index)
    {
        res = res * 10 + (str[index] - '0');
    }

    res = negative ? -res : res;
    */

    const char* tmp = (str[0] == '-') ? str+1 : str;
    while (*tmp != '\0')
    {
        res = res * 10 + (*tmp - '0');
        tmp++;
    }

    res = (str[0] == '-') ? -res : res;
}

int main(int argc, char** argv)
{
    char str[] = "-1029384756";
    int res = 0;

    stoi(str, res);

    std::cout << res << std::endl;

    return 0;
}
