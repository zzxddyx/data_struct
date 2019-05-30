/*************************************************************************
    > File Name: countbit1.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年05月26日 星期日 22时08分42秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define BITFLAG (0x1 << 7)

int countbit1(unsigned char c)
{
    int count = 0;
    unsigned char tmp = BITFLAG;

    for(int i = 0; i < sizeof(c)*8; ++i)
    {
        if((c & tmp) != 0)
            ++count;

        tmp >>= 1;
    }

    return count;
}

int count(unsigned char c)
{
    int count = 0;

    for(int i = 0; i < sizeof(c)*8; ++i)
    {
        if ((c & BITFLAG) != 0)
            ++count;

        c <<= 1;
    }

    return count;
}

int main(void)
{
    unsigned char tmp = 'a';
    //cout << tmp - '0' << endl;
    //cout << countbit1(tmp) << endl;
    cout << count(tmp) << endl;
    return 0;
}
