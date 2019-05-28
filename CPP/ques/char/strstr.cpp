#include <iostream>

const char* strstr(const char* mainstr, const char* substr)
{
    if (NULL == mainstr || NULL == substr)
        return NULL;

    const char* str = mainstr;
    const char* sub = substr;

    while(*str != '\0')
    {
        const char* strtmp = str;
        const char* subtmp = sub;

        while(*strtmp++ == *subtmp++);
        if(*subtmp == '\0')
            return str;

        str++;
        subtmp = sub;
    }

    return NULL;
}


int main(void)
{
    char str[] = "my name is liming is danny";
    char sub[] = "is";

    std::cout << strstr(str, sub) << std::endl;


    return 0;
}
