#include <iostream>

void changeStr(char* str)
{
    char* beg = str;

    while(*beg != '\0')
    {
        int index = 0;
        if (*beg >= 'a' && *beg <= 'z')
        {
            index = *beg-'a';
            index = (1 + index) % 26;
            *beg = 'a' + index;
        }
        else if (*beg >= 'A' && *beg <= 'Z')
        {
            index = *beg - 'A';
            index = (1 + index) % 26;
            *beg = 'A' + index;
        }
        else
        {
        }

        beg++;
    }
}

void revertStr(char* str)
{
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

void changeRevStr(char* str)
{
    if(str == NULL)
        return;

    changeStr(str);
    revertStr(str);
}

int main(void)
{
    char str[] = "JingXin HaoHaoShuoHua";
    std::cout << str << std::endl;
    changeRevStr(str);
    std::cout << str << std::endl;

    return 0;
}
