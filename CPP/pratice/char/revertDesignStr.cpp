#include <iostream>
#include <cstring>

void swap(char* c1, char* c2)
{
    *c1 ^= *c2;
    *c2 ^= *c1;
    *c1 ^= *c2;
}

void revertDesignStr(char *str, char* token)
{
    if (str == NULL || NULL == token)
        return;

    int len = strlen(str);
    char* beg = str;
    char* end = beg+len-1;

    while(beg < end)
    {
        swap(&(*beg), &(*end));

        beg++;
        end--;
    }

    for(int index = len; index >= 0; --index)
    {
        char* tmp = token;
        if(*tmp == str[index])
        {
            end = str+index;
            while(*tmp == str[index])
            {
                --index;
                tmp++;
            }

            if(*tmp == '\0')
            {
                beg = str+(++index);
                break;
            }
            else
            {
                tmp = token;
            }
        }
    }

    while(beg < end)
    {
        swap(&(*beg), &(*end));

        beg++;
        end--;
    }
}

int main(void)
{
    char str[] = "Welcome To Shanxi";
    char token[] = "To Shan";

    std::cout << str << std::endl;
    revertDesignStr(str, token);
    std::cout << str << std::endl;

    return 0;
}
