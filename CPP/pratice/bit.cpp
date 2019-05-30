/*************************************************************************
    > File Name: bit.c
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年05月26日 星期日 19时25分59秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define BIT3 (0x1<<3)
static int a;

void set_bit3(void)
{
    a |= BIT3;
}

void clear_bit3(void)
{
    a &= ~BIT3;
}

int main(void)
{
    cout << "1: " << BIT3 << " " << a << endl;
    set_bit3();
    cout << "2: " << BIT3 << " " << a << endl;
    clear_bit3();
    cout << "3: " << BIT3 << " " << a << endl;


    return 0;
}
