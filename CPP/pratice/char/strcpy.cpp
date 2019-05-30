#include <iostream>

const int size = 1024;

char* strcpy(char* destStr, const char* srcStr)
{
    if (NULL == destStr || NULL == srcStr)
        return NULL;

    char *destStrBegin = destStr;
  //  while((*destStr++ = *srcStr++) != '\0');
    while(*srcStr != '\0')
        *destStr++ = *srcStr++;

    return destStrBegin;
}

int main(void)
{
    char str[] = "abcdefg";
    char destArr[size] = "";
    char tmp[size] = "";

    strcpy(destArr, str);

    std::cout << strcpy(tmp, destArr) << std::endl;

    return 0;
}
