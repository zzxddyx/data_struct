#include <iostream>
#include <cstring>

void delStr(char *str, int pos, int len)
{
    if(NULL == str || pos < 0 || len <= 0)
        return;

    int strLen = strlen(str);
    if (pos >= strLen)
        return;

    if(pos+len >= strLen)
    {
        *(str+pos-1) = '\0';
        return;
    }

    char *delStart = str+pos-1;
    char *delFinish = str+pos+len-1; 

    while(*delFinish != '\0')
    {
        *delStart = *delFinish;
        delStart++;
        delFinish++;
    }

    *delStart = '\0';
}

int main(void)
{
    char str[] = "welcome to shanxi";

    std::cout << str << std::endl;
    delStr(str, 1, 7);
    std::cout << str << std::endl;



    return 0;
}
