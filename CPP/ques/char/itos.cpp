#include <iostream>

const int size = 1024;

void itoa(int num, char* res)
{
    if (res == NULL)
        return;

    int index = 0;
    int value = num < 0 ? -num : num;
    while(value != 0)
    {
        res[index++] = (value % 10) + '0';
        value /= 10;
    }
    if (num < 0)
        res[index++] = '-';
    res[index] = '\0';

    char* beg = res;
    char* end = res+(index-1);

    while(beg < end)
    {
        *beg ^= *end;
        *end ^= *beg;
        *beg ^= *end;

        beg++;
        end--;
    }
}

int main(void)
{
    int value = -1029384756;
    char res[size] = "";

    itoa(value, res);
    std::cout << res << std::endl;
    
    return 0;
}
