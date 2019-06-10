#include <iostream>
#include <cstring>

void swap(char *c1, char *c2)
{
    *c1 ^= *c2;
    *c2 ^= *c1;
    *c1 ^= *c2;
}

void sort(char *str, int strLen)
{
    for(int i = 1; i <= strLen; ++i)
    {
        for(int j = 0; j <= strLen-i; ++j)
        {
            if(str[j] > str[j+1])
            {
                swap(&(str[j]), &(str[j+1]));
            }
        }
    }
}

void turnstr(char *str, int len)
{
    int beg = 0;
    int mid = (len+1)/2;

    while(*(str+mid) != '\0')
    {
        *(str+beg) ^= *(str+mid);
        *(str+mid) ^= *(str+beg);
        *(str+beg) ^= *(str+mid);

        beg++;
        mid++;
    }
}

void sortANDturn(char *str)
{
    if(NULL == str)
        return;

    int len = strlen(str); 
    sort(str, len/2-1);

    // turn
    turnstr(str, len);
}

int main(void)
{
    char str[] = "lkjhgfdaa12345678";

    int len = strlen(str);
    std::cout << "strlen : " << len << std::endl;

    std::cout << str << std::endl;
    sortANDturn(str);
    std::cout << str << std::endl;

    return 0;
}
