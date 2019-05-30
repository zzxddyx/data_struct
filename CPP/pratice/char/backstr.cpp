#include <iostream>

bool backstr(const char* str)
{
    if (str == NULL)
        return false;

    const char* end = str;
    while(*end != '\0')
        ++end;
    --end;

    while(str < end)
    {
        if(*str != *end)
            return false;

        str++;
        end--;
    }

    return  true;
}

int main(void)
{
    //char str[] = "level";
    //char str[] = "abba";
    //char str[] = "aa";
    char str[] = "a";

    bool isback = backstr(str);
    std::cout << std::boolalpha << isback << std::endl;

    return 0;
}
