#include <iostream>

/*
 * str1 > str2 : 1
 * str1 < str2 : -1
 * str1 = str2 : 0
 */
int strcmp(const char* str1, const char* str2)
{
    int rst = 0;
    while(!(rst = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1)
    {
        str1++;
        str2++;
    }

    return (rst > 0) ? 1 : (rst < 0) ? -1 : rst;
}

int main(void)
{
    char str1[] = "abc";
    char str2[] = "bcd";

    std::cout << std::boolalpha << strcmp(str1, str2) << std::endl;
    std::cout << std::boolalpha << strcmp("abc", "abc") << std::endl;
    std::cout << std::boolalpha << strcmp("bcd", "abc") << std::endl;

    return 0;
}
