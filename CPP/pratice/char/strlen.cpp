#include <iostream>

int strlen1(const char* str)
{
    int len = 0;
    if (str == NULL)
        return len;

    while(*str++ != '\0')
        len++;

    return len;
}

int strlen(const char* str)
{
    int len = 0;
    if (NULL == str)
        return len;

    const char* tmp = str;
    while(*tmp++ != '\0');

    return tmp-str-1;
}

int main(void)
{
    char str[] = "ezfun";

    std::cout << strlen(str) << std::endl;

    return 0;
}
