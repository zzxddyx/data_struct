#include <iostream>
#include <cstring>

const int size = 1024;

char *replace(char *str, const char *sub, const char *repstr, char *output)
{
    if(str == NULL || output == NULL)
        return NULL;

    if(sub == NULL || repstr == NULL)
        return str;

    int sublen = strlen(sub);
    int replen = strlen(repstr);

    char *pstr = str;
    char *pres = output;

    while(*pstr != '\0')
    {
        pstr = strstr(pstr, sub);
        if(pstr != NULL)
        {
            memcpy(pres, str, pstr-str);
            pres += (pstr-str);
            memcpy(pres, repstr, replen);
            pres += replen;
            pstr += sublen;
            str = pstr;
        }
        else
        {
            break;
        }
    }

    *pres = '\0';
    if(*str != '\0')
        strcpy(pres, str);

    return output;
}


int main(void)
{
    char str[] = "welcome to tolanto";
    char sub[] = "to";
    char repstr[] = "love";
    char res[size] = "";

    std::cout << str << std::endl;
    std::cout << replace(str, sub, repstr, res) << std::endl;

    return 0;
}
