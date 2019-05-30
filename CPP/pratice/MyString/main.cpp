/*************************************************************************
    > File Name: main.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年05月30日 星期四 21时41分06秒
 ************************************************************************/

#include "MyString.h"

int main(void)
{
    MyString s1("hello ");
    MyString s2("C++");
    /*
    MyString s3(s1);
    MyString s4 = "come on";
    MyString s5 = s2;
    s5 = s4;
    s3.Print();
    s4.Print();
    s5.Print();
    */
    s1.Print();
    s2.Print();

    s1 = s1+s2;
    s1.Print();

    return 0;
}
