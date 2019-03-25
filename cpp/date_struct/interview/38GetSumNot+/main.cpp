/*************************************************************************
    > File Name: main.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月25日 星期一 21时43分39秒
 ************************************************************************/

#include <iostream>
using namespace std;

int Sum(int num1, int num2)
{
    int sum, carry;
    do
    {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;

        num1 = sum;
        num2 = carry;

    }while(num2 != 0);

    return sum;
}

int main(void)
{
    int num1 = 10;
    int num2 = 20;

    cout << Sum(num1, num2) << endl;

    return 0;
}
