#include <iostream>

char *strcat(char *dest, const char *src)
{
    if(NULL == dest)
        return NULL;

    if(NULL == src)
        return dest;

    char *res = dest;
    while(*dest++ != '\0');
    dest--;

    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    return res;
}

int main(void)
{
    char str[1024] = "hello";
    std::cout << strcat(strcat(str, " "), "world") << std::endl;

    return 0;
}
