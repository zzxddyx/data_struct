#include<iostream>
using namespace std;


bool equal(double num1, double num2)
{
    double res = num1-num2;
    if (res > -0.0000001 && res < 0.0000001)
        return true;
    else
        return false;
}

double getPowerNum(double base, unsigned int absExp)
{
    double res = 1.0;
    for (unsigned int i = 0; i < absExp; ++i)
    {
        res *= base;
    }
    return res;
}

/*
   a^n = a^(n/2) * a^(n/2);     (n为偶数)
   a^n = a^((n-1)/2) * a^((n-1)/2) * a  (n为基数)

 */
double getPowerNums(double base, unsigned int absExp)
{
    if (absExp == 0)
        return 1;
    if (absExp == 1)
        return base;

    double result = getPowerNums(base, absExp >> 1);
    result *= result;

    if (absExp & 0x01)
    {
        result *= base;
    }
    return result;
}

double Power(double base, int exp)
{
    if (equal(base, 0) && exp <= 0)
        return 0.0;

    unsigned int absExp = (unsigned int)(exp);
    if (exp < 0)
        absExp = (unsigned int)(-exp);

    double res = getPowerNums(base, absExp);

    if (exp < 0)
        res = 1.0/res;

    return res;
}


int main(void)
{
    double base = 10;
    int exp = -2;

    //double res = Power(base, exp);
    double res = Power(base, exp);

    cout << res << endl;

    return 0;
}
