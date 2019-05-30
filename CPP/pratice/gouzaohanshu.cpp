/*************************************************************************
    > File Name: gouzaohanshu.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年05月27日 星期一 21时20分25秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/*
class Test
{
    public:
        Test(){};
        Test(char *Name, int len = 0)
        {}
        Test(char *Name){}
};
*/

/*
class CLS
{
public:
    int m_i;
    CLS(int i)
        :m_i(i)
    {
        cout << "CLS(int) " << this << endl;
    }

    CLS()
    {
        cout << "CLS() " << this << endl;
        CLS(0);
    }
};
*/

class Number
{
    public:
        string type;
        Number()
            :type("void")
        {}

        explicit Number(short)
            :type("short")
        {}

        Number(int)
            :type("int")
        {}
};

void Show(const Number &obj)
{
    cout << obj.type << endl;
}

int main(void)
{
    //Test obj("hello");

    //CLS obj;
    //cout << "obj addr " << &obj << " data " << obj.m_i << endl;

    short s = 45;
    Show(s);

    return 0;
}
