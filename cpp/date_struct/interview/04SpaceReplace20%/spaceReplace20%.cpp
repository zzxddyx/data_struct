/*************************************************************************
  > File Name: spaceReplace20%.cpp
  > Author: BernieZhao
  > Mail: berniezhao@ezfun.cn
  > Created Time: 2019年03月12日 星期二 21时51分54秒
 ************************************************************************/

#include<iostream>
using namespace std;

void Replace(char str[], int len)
{
    if (str == NULL || len < 0)
        return;

    int i = 0;
    int orignLen = 0;
    int spaceCount = 0;

    while(str[i] != '\0')
    {
        orignLen++;

        if(str[i] == ' ')
        {
            spaceCount++;
        }
        i++;
    }

    int newLen = orignLen + spaceCount*2;
    if (newLen > len)
    {
        cout << "len error" << endl;
        return;
    }

    int indexOfOrign = orignLen;
    int indexOfNew = newLen;

    while(indexOfOrign >= 0 && indexOfNew > indexOfOrign)
    {
        if (str[indexOfOrign] == ' ')
        {
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        }
        else
        {
            str[indexOfNew--] = str[indexOfOrign];
        }

        indexOfOrign--;
    }
}


int main(void)
{
    char str[20] = "We Are Happy.";
    int len = sizeof(str)/sizeof(str[0]);

    Replace(str, len);

    cout << str << endl;

    return 0;
}
