#include <iostream>
#include <cstring>

void rightMoveStr(char* str, int n)
{
    if (str == NULL || n <= 0)
        return;

    int len = strlen(str);
    if(n > len)
        return;

    char* newArr = new char[len];
    memcpy(newArr, str+len-n, n);
    memcpy(newArr+n, str, len-n);
    memcpy(str, newArr, len);

    delete []newArr;
    newArr = NULL;
}

void swap(char* beg, char* end)
{
    while(beg < end)
    {
        *beg ^= *end;
        *end ^= *beg;
        *beg ^= *end;

        beg++;
        end--;
    }
}

void rightMove(char* str, int n)
{
    if (NULL == str || n <= 0)
        return;

    int len = strlen(str);
    if (n > len)
        return;

    swap(str+len-n, str+len-1);
    swap(str, str+len-n-1);
    swap(str, str+len-1);
}

int main(void)
{
    char str[] = "abcdefg";
    std::cout << str << std::endl;
    //rightMoveStr(str, 3);
    rightMove(str, 3);
    std::cout << str << std::endl;

    return 0;
}
