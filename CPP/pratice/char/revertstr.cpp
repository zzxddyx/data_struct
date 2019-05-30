#include <iostream>

void swap(char* c1, char* c2)
{
    *c1 ^= *c2;
    *c2 ^= *c1;
    *c1 ^= *c2;
}

void revert(char* pstr)
{
    if(NULL == pstr)
        return;

    char *beg = pstr;
    char *end = pstr;

    while(*end != '\0')
        ++end;
    --end;

    while(beg < end)
    {
        swap(&(*beg), &(*end));
        beg++;
        end--;
    }

    beg = end = pstr;
    char *str = pstr;
    while(*str++ != '\0')
    {
        if(*str == ' ' || *str == '\0')
        {
            end = str-1;
            while(beg < end)
            {
                swap(&(*beg), &(*end));
                beg++;
                end--;
            }
            beg = end = (str + 1);
        }
    }
}

int main(void)
{
    char str[] = "welcome to china";
    std::cout << str << std::endl;
    revert(str);
    std::cout << str << std::endl;

    return 0;
}
