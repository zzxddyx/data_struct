#include <iostream>
#include <cstring>

const int arraySize = 1024;

int getlen(char* str)
{
    if (NULL == str)
        return 0;

    char* tmp = str;
    int len = 0;
    while(*tmp != '\0')
    {
        tmp++;
        len++;
    }
    return len;
}

void transformation(char* str)
{
    if(NULL == str)
        return;

    char* pstr = str;
    char* next = pstr+1;
    int count = 1;

    while(*next != '\0')
    {
        if(*pstr == *next)
        {
            ++count;
        }
        else
        {
            int lesslen = getlen(next);
            std::cout << lesslen << std::endl;
            memmove(next+1, next, lesslen);
            *next = count;
        }
        ++pstr;
        ++next;
    }
}

int main(void)
{
    char arr[arraySize] = "aaaabbbccd";
    std::cout << arr << std::endl;
    transformation(arr);
    std::cout << arr << std::endl;




    return 0;
}
