#include <iostream>

int gNum = 10;

int change(int n)
{
    gNum *= n;
    return gNum;
}

int main(void)
{
    int n = 5;

    int res = change(n);
    int& refRes = res;
    //i//nt& refRes = change(n);
       //
    std::cout << refRes << std::endl;
    return 0;
}
