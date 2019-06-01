#include <iostream>
#include <cstring>

char* addStr(char* str1, char* str2)
{
    if(NULL == str1 || NULL == str2)
        return NULL;

    int str1len = strlen(str1);
    int str2len = strlen(str2);
    int newlen = str1len > str2len ? str1len+2 : str2len+2; // 进位预先占一位
    char* res = new char[newlen];

    int str1Index = str1len - 1;
    int str2Index = str2len - 1;
    int carry = 0;
    int resIndex = 0;
    while(str1Index >= 0 && str2Index >= 0)
    {
        int sum = (str1[str1Index] - '0') + (str2[str2Index] - '0') + carry;
        res[resIndex] = sum % 10 + '0';
        carry = sum / 10;

        str1Index--;
        str2Index--;
        resIndex++;
    }

    while(str1Index >= 0)
    {
        int sum = str1[str1Index] - '0' + carry;
        res[resIndex] = sum % 10 + '0';
        carry = sum / 10;

        str1Index--;
        resIndex++;
    }

    while(str2Index >= 0)
    {
        int sum = str2[str2Index] - '0' + carry;
        res[resIndex] = sum % 10 + '0';
        carry = sum / 10;

        str2Index--;
        resIndex++;
    }

    if(carry > 0)
        res[resIndex++] = carry + '0';
    res[resIndex] = '\0';

    char* beg = res;
    char* end = res;
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

    return res;
}

int main(void)
{
    char str1[] = "56789";
    char str2[] = "987654321";

    char* res = addStr(str1, str2);
    if (res != NULL)
    {
        std::cout << res << std::endl;
        delete []res;
        res = NULL;
    }

    return 0;
}
/*
 * 011111111
 * 123456789
 *
 * 987711110
 * 000056789
 * 987654321
 */
