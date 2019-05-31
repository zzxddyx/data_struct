#include <iostream>
#include <cstring>

char* dec2bin(unsigned int num)
{
    char* res = new char[32];
    memset(res, '0', 32);

    for (int i = 31; i >= 0; --i)
    {
        int c = num & (1 << i);
        res[32-i-1] = (c > 0) ? '1' : '0';
    }

    return res;
}

void d_dec2bin(int num)
{
    if(num/2 > 0)
        dec2bin(num/2);

    std::cout << num%2;
}

char* dec2hex(unsigned int num)
{
    char* res = new char[8];
    memset(res, '0', 8);

    for(int i = 7; i >= 0; --i)
    {
        int c = 15 & (num >> (4*i));
        char hexnum = (c >= 10) ? ('A'+c-10) : (c+'0');
        res[7-i] = hexnum;
    }

    return res;
}

void d_dec2hex(int num)
{
    if(num/16 > 0)
        dec2hex(num/16);

    char c = num%16 >= 10 ? 'A'+(num%16)-10 : '0'+num%16;
    std::cout << c;
}

int main(void)
{
    //int num = 954;
    int num = 14;

    char* bin = dec2bin(num);
    std::cout << bin << std::endl;
    delete []bin;
    bin = NULL;

    bin = dec2hex(num);
    std::cout << bin << std::endl;
    delete []bin;
    bin = NULL;

    return 0;
}
