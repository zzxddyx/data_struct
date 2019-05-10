#include <iostream>

void delSpace(char* str)
{
    if (str == NULL)
        return;

    char* pStart = str;
    char* pEnd = str;

    while(*pEnd != '\0')
    {
        if (*pEnd != '\0' && *pEnd != ' ')
        { 
            *pStart++ = *pEnd;
        }
        pEnd++;
    }
    *pStart='\0';
}

int main(void)
{
    char str[] = "Hello Java C++ and Lua or Json";
    std::cout << str << std::endl;

    delSpace(str);
    std::cout << str << std::endl;

    return 0;
}
