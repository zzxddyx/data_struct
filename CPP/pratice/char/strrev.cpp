#include <iostream>

void strrev(char* str)
{
    if(NULL == str)
        return;

    char* beg = str;
    char* end = str;
    while(*end != '\0')
        ++end;
    --end;

    while(beg < end)
    {
        *beg ^= *end;
        *end ^= *beg;
        *beg ^= *end;

        beg++;
        end--;
    }
}

int main(int argc, char** argv)
{
    char str[] = "Welcome to Shanxi!";
    std::cout << str << std::endl;
    strrev(str);
    std::cout << str << std::endl;

    return 0;
}
