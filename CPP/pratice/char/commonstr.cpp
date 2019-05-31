#include <iostream>                                                                       
#include <cstring>

void commonstring(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    // 长字符串放外层,短字符串放内层
    if (len1 < len2)
    {
        char* tmp = str1;
        str1 = str2;
        str2 = tmp;
    }

    int maxcommonlen = 0;
    char* commonstart = NULL;
    while (*str1 != '\0')
    {
        if (len1 < maxcommonlen)
            break;

        char* str1tmp = str1;
        char* str2tmp = str2;
        while (*str2tmp != '\0')
        {
            str1tmp = str1;
            char* pstr2 = str2tmp;
            int curcommonlen = 0;
            while (*str1tmp != '\0' && *str2tmp != '\0' && *str1tmp == *str2tmp)
            {
                ++str1tmp;
                ++str2tmp;
                ++curcommonlen;
            }

            if (curcommonlen > maxcommonlen)
            {
                maxcommonlen = curcommonlen;
                commonstart = pstr2;
            }

            ++str2tmp;
        }

        str1++;
        len1--;
    }

    while (maxcommonlen--)
    {
        std::cout << *commonstart++;
    }
    std::cout << std::endl;
}

int main(void)
{
    char str1[] = "welcome to china133456789";
    char str2[] = "welcome too china123456789";

    commonstring(str1, str2);

    return 0;
}
