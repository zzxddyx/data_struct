#include <iostream>

void calucate(const char* str, int *num1, int* num0)
{
    if(NULL == str)
    {
        *num0 = *num1 = 0;
        return;
    }
    const char* pstr = str;
    const char* tmp = NULL;
    int count = 1;

    while(*pstr != '\0')
    {
        count = 1;
        if ('0' == *pstr) 
        {
            tmp = pstr+1;
            if (*pstr == *tmp)
            {
                while(*tmp != '\0' && *pstr == *tmp)
                {
                    ++count;
                    ++pstr;
                    ++tmp;
                }
                if (count > *num0)
                    *num0 = count;
            }
            else
            {
                ++pstr;
            }
        }
        else if('1' == *pstr)
        {
            tmp = pstr+1;
            if (*pstr == *tmp)
            {
                while(*tmp != '\0' && *pstr == *tmp) 
                {
                    ++count;
                    ++pstr;
                    ++tmp;
                }
                if(count > *num1)
                    *num1 = count;
            }
            else
            {
                ++pstr;
            }
        }
        else
        {
            ++pstr;
        }
    }
}

int main(void)
{
    char str[] = "1111100101110000001111111100000";
    int count1 = 0;
    int count0 = 0;

    calucate(str, &count1, &count0);

    std::cout << count0 << " " << count1 << std::endl;

    return 0;
}
