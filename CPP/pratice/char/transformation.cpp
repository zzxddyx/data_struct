#include <iostream>
#include <cstring>
#include <cstdio>

const int arraySize = 1024;

void transformation(char* str)
{
    if(NULL == str)
        return;

    int len = strlen(str);
    char* tmpArr = new char[len+1];

    char* pstr = str;
    char* next = pstr+1;
    int count = 1;

    while(*next != '\0')
    {
        if(*pstr == *next)
        {
            ++pstr;
            ++next;
            ++count;
        }
        else
        {
            sprintf(tmpArr, "%d", count);
            int tmpLen = strlen(tmpArr);
            strcat(tmpArr, next);
            *next = '\0';
            strcat(str, tmpArr);
            next += tmpLen;
            pstr = next;
            next = pstr+1;
            count=1;
        }
    }

    sprintf(tmpArr, "%d", count);
    strcat(str, tmpArr);

    delete []tmpArr;
    tmpArr = NULL;
}

int main(void)
{
    char arr[arraySize] = "aaaaaaaaaaa";
    std::cout << arr << std::endl;
    transformation(arr);
    std::cout << arr << std::endl;




    return 0;
}
